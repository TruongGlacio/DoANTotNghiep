#include "PeopleDetectManager.h"
#include <ConstDefines.h>
#include<MouseController.h>
#include<ConstDefines.h>
#include <QTimer>
#include<QDebug>
#include<VTIUtility.h>
#include<QtConcurrent>
#define CLIENT_CONNECTED "Client connected"
// contructor
#ifdef TEST_ON_PC
QTimer *timer;
#endif
PeopleDetectManager::PeopleDetectManager(QObject *parent) : QObject(parent)
{
    SetUrl(DEFAULT_ADDRESS_WEBSERVER);
    mMouseController=new MouseController();
    qRegisterMetaType<QAbstractSocket::SocketState>();
    qRegisterMetaType<QList<QSslError>>();
    qRegisterMetaType<QAbstractSocket::SocketError>();
#ifdef TEST_ON_PC
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(testOpenScreen()));
    timer->setInterval(10000);
    timer->start();
#endif
}
#ifdef TEST_ON_PC
void PeopleDetectManager::testOpenScreen()
{
    static int count = 0;
    bool isP = true;
    qDebug() << "PeopleDetectManager::testOpenScreen()";
    count++;
    if (count > 15)
    {
        isP = false;

        if (count > 30)
        {
            count = 0;
        }
    }

    emit DetectPeople(isP);
    timer->setInterval(500);
    timer->stop();
}
#endif
// Creat a new connect to web socket server
void PeopleDetectManager::OpenConnection()
{
    mWebSocket.open(QUrl(mUrl));
    qDebug() << "WebSocket connecting";
    connect(&mWebSocket, &QWebSocket::connected, this, &PeopleDetectManager::onConnected);
    connect(&mWebSocket, &QWebSocket::textMessageReceived, this, &PeopleDetectManager::OnDataChange);
    connect(this, &PeopleDetectManager::SendLocationData,this, &PeopleDetectManager::PrintData);
    connect(this,&PeopleDetectManager::SendTextMessageChange,&mWebSocket, &QWebSocket::sendTextMessage);
    connect(&mWebSocket, QOverload<const QList<QSslError>&>::of(&QWebSocket::sslErrors),
            this, &PeopleDetectManager::HandlingSocketError);
    connect(&mWebSocket, & QWebSocket::disconnected, this, &PeopleDetectManager::Disconnected);
    connect(this, &PeopleDetectManager::SendLocationData, mMouseController, &MouseController::LocaltionHandle);
    connect(this,&PeopleDetectManager::DetectPeople,mMouseController,&MouseController::DataDetectHandle);
}

// Handler data when connection of socket was connnected
void PeopleDetectManager::onConnected()
{
    qDebug() << "WebSocket connected";

    QString msg=CLIENT_CONNECTED;
    mWebSocket.sendTextMessage(CLIENT_CONNECTED);
    emit SendTextMessageChange(msg);
}

// Send message to web socket server
void PeopleDetectManager::SendMessage(QString message)
{
    emit SendTextMessageChange(message);
}

// Handler detect data package
QJsonObject PeopleDetectManager::OnReciverData(QString data)
{
    QJsonObject jsonObject;
    QJsonParseError *error = nullptr;
    QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8(),error );
    if(!doc.isNull())
    {
        if(doc.isObject())
        {
            jsonObject = doc.object();
            DetectJsonData(jsonObject);
            qDebug() << "Document is an json object" << endl;
        }
        else
        {
            qDebug() << "Document is not an json object" << endl;
        }
    }
    else
    {
        qDebug() << "Invalid JSON...\n" << data << endl;
    }
    return jsonObject;
}

// Handle disconnect and close socket connection
void PeopleDetectManager::WebSocketDiconnect()
{
    mWebSocket.close(QWebSocketProtocol::CloseCodeNormal, "Close connect");
}

// handle  recive data from websocket
void PeopleDetectManager::OnDataChange(QString message)
{
    qDebug() << "Message received:" << message;
    QFuture<void> future = QtConcurrent::run([=]() {
        // Code in this block will run in another thread
        this->mJsonObject = OnReciverData(message);
    });

}

//handle error when web socket error happen
void PeopleDetectManager::HandlingSocketError(const QList<QSslError> &errors)
{
    Q_UNUSED(errors);
    qDebug() << "SocketError received:";
    // WARNING: Never ignore SSL errors in production code.
    // The proper way to handle self-signed certificates is to add a custom root
    // to the CA store.
    emit SendErrorToControl(errors);
    mWebSocket.ignoreSslErrors();
}

// test function
void PeopleDetectManager::PrintData(QPoint dataPackage)
{
    qDebug() << "Data print  is \n X="<<dataPackage.x()<<"\n Y="<<dataPackage.y()<<endl;
}

// Handle function when websocket disconnect
void PeopleDetectManager::Disconnected()
{
    qDebug() << "WebSocket disconnected";
    disconnect(&mWebSocket,0,0,0);
    disconnect(this, &PeopleDetectManager::SendLocationData,0,0);
    disconnect(this,&PeopleDetectManager::SendTextMessageChange,0,0);
}

//Handle detect JsonData recive from web socket
void PeopleDetectManager::DetectJsonData(QJsonObject jsonObject)
{

    QPoint qpoint(1,1);
    DectectHandData dataPackage;
    bool  detectResult = true;
    dataPackage.box_center = qpoint;
    QString  event = jsonObject.value(DETECT_EVENT).toString();
    QJsonValue   data = jsonObject.value(QString(DETECT_DATA));
    QString  source = jsonObject.value(DETECT_SOURCE).toString();
    if(source == DETECT_HAND){

        //detect data is mourse localtion
        dataPackage=VTIUtility::ReadDectectHandDataJson(jsonObject);
        //detect score list
        qDebug() << "box_center value :X=" << dataPackage.box_center.x()<<"Y="<<dataPackage.box_center.y()<< endl;
        emit SendLocationData(dataPackage.box_center);
        emit DetectPeople(detectResult);
    }
    else if (source == DETECT_FACE) {
        // detect data is detect result
        if(data == DETECT_DETECTED) {
            detectResult = true;
        }
        else if (data == DETECT_NO_DETECTED) {
            detectResult = false;
        }
        qDebug() << " Data detect results \n data="<<detectResult<<endl;
        emit DetectPeople(detectResult);
    }
    qDebug() << "Data detect is \n event="<<event<<" \n data="<<data<<"\n source="<<source<<endl;
}

// Set url connect to web socket
void PeopleDetectManager::SetUrl(QString url)
{
    this->mUrl = (QUrl(url));
}

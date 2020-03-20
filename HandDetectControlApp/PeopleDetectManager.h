#ifndef WEBSOCKETCLIENT_H
#define WEBSOCKETCLIENT_H
#include <QObject>
#include <QString>
#include <QtCore>
#include <QtWebSockets/QWebSocket>
#include <QtNetwork/QSslError>
#include<QJsonObject>
#include<QJsonParseError>
#include <QMutexLocker>
class MouseController;
class PeopleDetectManager :public QObject
{
    Q_OBJECT
public:
    explicit PeopleDetectManager(QObject *parent = nullptr);

    void OpenConnection();
    void SendMessage( QString message);
    void SetUrl(QString mUrl);


signals:
    void SendTextMessageChange( QString &message);
    void SendLocationData(QPoint qpoint);
    void CloseConnectionChange(QWebSocketProtocol::CloseCode closeCode = QWebSocketProtocol::CloseCodeNormal, const QString &reason = QString());
    void SendErrorToControl(const QList<QSslError> &errors);
    void DetectPeople(bool detectResult);
public slots:
    void onConnected();
    void WebSocketDiconnect();
    void OnDataChange(QString message);
    void HandlingSocketError(const QList<QSslError> &errors);
    void PrintData(QPoint dataPackage);
    void Disconnected();
#ifdef TEST_ON_PC
    void testOpenScreen();
#endif
private:
    QJsonObject OnReciverData(QString data);
    void DetectJsonData(QJsonObject  mJsonObject);
    MouseController *mMouseController;
    QJsonObject mJsonObject;
    QWebSocket mWebSocket;
    QUrl mUrl;
};

#endif // WEBSOCKETCLIENT_H

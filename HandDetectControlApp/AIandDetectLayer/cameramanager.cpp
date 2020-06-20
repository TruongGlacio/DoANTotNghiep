#define IMAGE_HIGH_QUALITY 3 //HighQuality
#define IMAGE_HEIGHT_SIZE 720
#define IMAGE_WIDTH_SIZE 1280
#define IMAGE_FORMAT "png"
#include "cameramanager.h"
QVector<processParameter> parametersTable;

CameraManager::CameraManager(QObject *parent,QApplication *mApp) : QObject(parent)
{
    qRegisterMetaType<cv::Mat>();
    qRegisterMetaType<QVector<int>>();
    qRegisterMetaType<QVector<double>>();

    QLocale::setDefault(QLocale(QLocale::English, QLocale::UnitedStates));
   // QApplication qtApp(argc, argv);
  //  qtApp.setStyle(QStyleFactory::create("Fusion"));
    initParameters();

    QMainWindow window;
    window.setStyleSheet("background-color: rgb(0, 0, 0);");
    qDebug() << "camera running";


    QThread processThread;
    processThread.setParent(&window);
    mProcessFrame.moveToThread(&processThread);
    mCamCapture.moveToThread(&processThread);
    processThread.start();

    QObject::connect(&mWidget, SIGNAL(sendParameters(QString,int)), &mProcessFrame, SLOT(getParameters(QString,int)));
   // QObject::connect(&mimageBox, SIGNAL(GetMouseLocation(QPoint)), &mMouseController, SLOT(SetMouseLocation(QPoint)));
    QObject::connect(&mWidget, SIGNAL(ready()), &mCamCapture, SLOT(getFrame()));
    QObject::connect(&mCamCapture, SIGNAL(frameReady(cv::Mat)), &mProcessFrame, SLOT(processFrame(cv::Mat)));
    QObject::connect(&mProcessFrame, SIGNAL(imageReady(QByteArray)), &mWidget, SLOT(getImage(QByteArray)));
    QObject::connect(&mWidget, SIGNAL(sendSamplePosition(int,int)), &mProcessFrame, SLOT(getSamplePosition(int,int)));
    QObject::connect(&mProcessFrame, SIGNAL(sendCenterPosition(int,int,double)), &mWidget, SLOT(getCenterPosition(int,int,double)));
    QObject::connect(&mProcessFrame, SIGNAL(sendFingers(QVector<int>)), &mWidget, SLOT(getFingers(QVector<int>)));
    QObject::connect(&mProcessFrame, SIGNAL(sendVector(int, QVector<double>)), &mWidget, SLOT(getVector(int, QVector<double>)));

    window.setCentralWidget(&mWidget);
    window.showNormal();
    bool resultInvolke = QMetaObject::invokeMethod(&mCamCapture, "getFrame");
    if(resultInvolke==false)
    {
        qDebug()<<" involke false";
    }
    mApp->exec();
    processThread.quit();
    processThread.wait();
}

CameraManager::~CameraManager()
{

}

void CameraManager::initParameters()
{
    parametersTable.append(processParameter("mirror"    ,   0,   1,   1));
    parametersTable.append(processParameter("channel"   ,   0,   2,   2));
    parametersTable.append(processParameter("output"    ,   0,  10,   2));
    parametersTable.append(processParameter("blend"     ,   0, 100,  32));
    parametersTable.append(processParameter("sigma"     ,   0,  20,   8));
    parametersTable.append(processParameter("huePicker" , -90,  90,   5));
    parametersTable.append(processParameter("satPicker" ,   0, 255, 155));
    parametersTable.append(processParameter("median"    ,   1,  49,  19));
    parametersTable.append(processParameter("threshold" ,   0, 255, 190));
}

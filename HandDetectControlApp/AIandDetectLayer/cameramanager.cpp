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
    camWidget widget;
    cvCamCapture camCapture;
    cvProcessFrame processFrame;

    QThread processThread;
    processThread.setParent(&window);
    processFrame.moveToThread(&processThread);
    camCapture.moveToThread(&processThread);
    processThread.start();

    QObject::connect(&widget, SIGNAL(sendParameters(QString,int)), &processFrame, SLOT(getParameters(QString,int)));
    QObject::connect(&widget, SIGNAL(ready()), &camCapture, SLOT(getFrame()));
    QObject::connect(&camCapture, SIGNAL(frameReady(cv::Mat)), &processFrame, SLOT(processFrame(cv::Mat)));
    QObject::connect(&processFrame, SIGNAL(imageReady(QByteArray)), &widget, SLOT(getImage(QByteArray)));
    QObject::connect(&widget, SIGNAL(sendSamplePosition(int,int)), &processFrame, SLOT(getSamplePosition(int,int)));
    QObject::connect(&processFrame, SIGNAL(sendCenterPosition(int,int,double)), &widget, SLOT(getCenterPosition(int,int,double)));
    QObject::connect(&processFrame, SIGNAL(sendFingers(QVector<int>)), &widget, SLOT(getFingers(QVector<int>)));
    QObject::connect(&processFrame, SIGNAL(sendVector(int, QVector<double>)), &widget, SLOT(getVector(int, QVector<double>)));

    window.setCentralWidget(&widget);
 //   window.showNormal();
    bool resultInvolke = QMetaObject::invokeMethod(&camCapture, "getFrame");
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

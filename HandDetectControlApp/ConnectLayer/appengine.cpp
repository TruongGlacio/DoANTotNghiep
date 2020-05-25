#include "appengine.h"

AppEngine::AppEngine(QObject *parent) : QObject(parent)
{
    mMouseController=new MouseController();
 //  connect(mCameramanager, SIGNAL(getImagePath(QString)), this, SLOT(ImagePath(QString)));
//   CaptureImage();
//   if(mCameramanager->CheckAvaiableCamera()){
//       qDebug()<<"Camera is avaiable ";
//       mCameramanager->setCamera(QCameraInfo::defaultCamera());
//       CaptureImage();
   //}
}

void AppEngine::CaptureImage()
{
    qDebug()<<"Timer take image running";
     timer= new QTimer(this);
     connect(timer, SIGNAL(timeout()), mCameramanager, SLOT(takeImage()));
     timer->start(300);
}

void AppEngine::ExcuteCamProcess(QApplication *mApp)
{
    mCameramanager=new CameraManager(mApp);
}

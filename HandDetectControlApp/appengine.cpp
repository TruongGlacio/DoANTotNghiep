#include "appengine.h"

AppEngine::AppEngine(QObject *parent) : QObject(parent)
{
    mMouseController=new MouseController();
    mCameramanager=new CameraManager();

   connect(mCameramanager, SIGNAL(getImagePath(QString)), this, SLOT(ImagePath(QString)));
   if(mCameramanager->CheckAvaiableCamera()){
       CaptureImage();
   }
}

void AppEngine::CaptureImage()
{
     timer= new QTimer(this);
     connect(timer, SIGNAL(timeout()), this, SLOT(mCameramanager->takeImage()));
     timer->start(1000);
}

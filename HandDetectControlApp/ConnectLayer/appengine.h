#ifndef APPENGINE_H
#define APPENGINE_H

#include <QObject>
#include"UserControlLayer/MouseController.h"
#include"AIandDetectLayer/cameramanager.h"
#include <QTimer>
class AppEngine : public QObject
{
    Q_OBJECT
public:
    explicit AppEngine(QObject *parent = nullptr);
    void CaptureImage();

signals:
    void ImagePath(QString imagePath);

public slots:

    void ExcuteCamProcess(QApplication *mApp);
private:
    MouseController *mMouseController;
    CameraManager *mCameramanager;
    QTimer *timer;

};

#endif // APPENGINE_H

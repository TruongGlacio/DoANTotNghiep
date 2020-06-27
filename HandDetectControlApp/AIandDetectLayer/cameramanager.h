#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H
#include <QApplication>
#include <QMainWindow>
#include <QStyleFactory>
#include <QtGui>

#include "AIandDetectLayer/global.h"
#include "AIandDetectLayer/camWidget.h"
#include "AIandDetectLayer/camProcess.h"
#include <QApplication>
#include"UserControlLayer/MouseController.h"
class CameraManager : public QObject
{

    Q_OBJECT
public:
    explicit CameraManager(QObject *parent = nullptr,QApplication *mApp=nullptr);
    ~CameraManager();
    void initParameters();
public:

};

#endif // CAMERAMANAGER_H

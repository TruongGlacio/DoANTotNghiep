#include"MouseController.h"
#include <QPixmap>
#include <QGuiApplication>
#include <QScreen>
#include <QDebug>
#include"ConnectLayer/ConstDefines.h"
MouseController::MouseController(QObject *parent):QObject (parent)
{
    SetMouseSourse(ICON_HAND);
}


void MouseController::SetMouseSourse(QString iconName)
{
    QImage myImage;
    myImage.load(iconName);
    QPixmap cursor_pixmap(iconName);
    cursor_pixmap.fromImage(myImage);
    mQcusor.setShape(Qt::BitmapCursor);
    mQcusor = QCursor(cursor_pixmap, cursor_pixmap.width()/2,cursor_pixmap.height()/2);
    QGuiApplication::setOverrideCursor(mQcusor);
}

void MouseController::CheckLocation(QPoint locationMouse)
{
    // detect screen mouse focussing
    QScreen *screen = QGuiApplication::screenAt(locationMouse);
    QRect  screenGeometry = screen->geometry();
    int x = screenGeometry.x();
    int y = screenGeometry.y();
    int height = screenGeometry.height();
    int width = screenGeometry.width();
    qDebug()<<"x="<<x<<"\n y="<<y<<"\n height="<<height<<"\n width="<<width<<endl;

    QPoint qpointMouse;
    qpointMouse = mQcusor.pos();
    // emit when detect mouse longpress to location on screen
    emit MouseLongPress(locationMouse);
    // emit when detect mouse press to left screen location on screen

    if(qpointMouse.x() == screenGeometry.left())

        emit MouseInLeftScreen(locationMouse);
    // emit when detect mouse press to right screen location on screen
    if(qpointMouse.x() == screenGeometry.right())
        emit MouseInRightScreen(locationMouse);

    // emit when detect mouse press to right screen location on screen
    if(qpointMouse.y() == screenGeometry.top())
        emit MouseInTopScreen(locationMouse);

    // emit when detect mouse press to right screen location on screen
    if(qpointMouse.y() == screenGeometry.bottom())
        emit MouseInBottomScreen(locationMouse);

}

void MouseController::DataDetectHandle(bool result)
{

}

void MouseController::LocaltionHandle(QPoint qpoint)
{
    SetMouseLocation(qpoint);
}

void MouseController::ErrorHandler(const QList<QSslError> &errors)
{

}

void MouseController::SetLocationOffSet(QPoint locationMouse)
{
    QRect recDesktop = QGuiApplication::primaryScreen()->geometry();
    QScreen *screen = QGuiApplication::screenAt(locationMouse);
    QRect  screenGeometry = screen->geometry();
    QPoint qpointOffset=QPoint(screenGeometry.x(),screenGeometry.y());
    this->mQpointOffsett = qpointOffset;
    this->mScaleHeight = recDesktop.height()/CAM_HEIGHT;
    this->mScaleWidth = recDesktop.width()/CAM_WIDTH;
    qDebug() << "OffsetX="<<qpointOffset.x()<<"\n OffsetY="<<qpointOffset.y()<<"\n scaleHeight="<<this->mScaleHeight<<"\n scaleWidth="<<this->mScaleWidth<<endl;

}

void MouseController::SetMouseLocation(QPoint qpoint)
{
    qDebug() << "qpointmouseX="<<qpoint.x()<<"\n qpointmouseY="<<qpoint.y()<<endl;
    SetLocationOffSet(qpoint);
    mQcusor.setPos(this->mQpointOffsett.x()+qpoint.x()*DESKTOP_PIXEL_WIDTH/CAM_WIDTH,this->mQpointOffsett.y()+qpoint.y()*DESKTOP_PIXEL_HEIGHT/CAM_HEIGHT);
   // mQcusor.setPos(qpoint.x(),qpoint.y());
    //CheckLocation(qcusor.pos());
    qDebug() << "mouseX="<<mQcusor.pos().x()<<"\n mouseY="<<mQcusor.pos().y()<<endl;
}

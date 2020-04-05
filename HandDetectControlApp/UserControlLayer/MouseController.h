#ifndef SCREENCONTROLLER_H
#define SCREENCONTROLLER_H

#define ICON_HAND ":/Qml/Images/icon_hand.png"
#define CIRCLE_BLUE ":/Qml/Images/Circle_blue.png"
#define RING_CIRCLE_BLUE ":/Qml/Images/Ring_Circle_blue.png"
#define RING_CIRCLE_YELLOW ":/Qml/Images/Ring_Circle_yellow.png"
#include <QObject>
#include <QtNetwork/QSslError>
#include <QCursor>
#include <Qt>
class MouseController : public QObject
{
    Q_OBJECT
public:
    explicit MouseController(QObject *parent = nullptr);

signals:
        void MouseLongPress(QPoint locationMouse);
        void MouseInLeftScreen(QPoint locationMouse);
        void MouseInRightScreen(QPoint locationMouse);
        void MouseInTopScreen(QPoint locationMouse);
        void MouseInBottomScreen(QPoint locationMouse);
public slots:
    void SetMouseSourse(QString iconName);
    void DataDetectHandle(bool result);
    void LocaltionHandle(QPoint qpoint);
    void ErrorHandler(const QList<QSslError> &errors);
    void SetLocationOffSet(QPoint locationMouse);
private:

    void CheckLocation(QPoint locationMouse);
    void SetMouseLocation(QPoint qpoint);
    QPoint mQpointOffsett;
    int mScaleHeight;
    int mScaleWidth;
    QCursor mQcusor;

};

#endif // SCREENCONTROLLER_H

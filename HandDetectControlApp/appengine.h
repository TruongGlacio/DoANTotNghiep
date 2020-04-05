#ifndef APPENGINE_H
#define APPENGINE_H

#include <QObject>
#include"UserControlLayer/MouseController.h"
class AppEngine : public QObject
{
    Q_OBJECT
public:
    explicit AppEngine(QObject *parent = nullptr);

signals:

public slots:

private:
    MouseController *mMouseController;

};

#endif // APPENGINE_H

#include "appengine.h"

AppEngine::AppEngine(QObject *parent) : QObject(parent)
{
    mMouseController=new MouseController();

}

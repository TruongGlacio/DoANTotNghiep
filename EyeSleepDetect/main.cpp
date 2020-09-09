#include <QApplication>
#include <QQmlApplicationEngine>
#include "FacesDetectClass.h"
#include"cameramanager.h"
#include"appenginer.h"
#include <QQmlContext>
#include <QtQml>
#include <QQmlEngine>
int main(int argc, char *argv[])
{
    FUNCTION_LOG();

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);
    CameraManager *mCameramanager=new CameraManager();

    QQmlApplicationEngine engine;
#if __linux__
    /*using for linux, qmlRegisterSingletonInstance not exit on linux */
    engine.rootContext()->setContextProperty("CameraManager", mCameramanager);
#else
    /*using for windown*/
    engine.rootContext()->setContextProperty("CameraManager", mCameramanager);

  //  QScopedPointer<CameraManager> service(mCameramanager);
  //  qmlRegisterSingletonInstance<CameraManager>("Application.CameraManager", 1, 0, "CameraManager", service.get());
#endif

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    QObject *obj=engine.rootObjects().first();
    AppEnginer *mAppEnginer=new AppEnginer(obj,mCameramanager);
    return app.exec();
}

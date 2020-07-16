#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "FacesDetectClass.h"
#include"cameramanager.h"
#include"appenginer.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    FUNCTION_LOG();

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    CameraManager *mCameramanager=new CameraManager();
    QScopedPointer<CameraManager> service(mCameramanager);
    qmlRegisterSingletonInstance<CameraManager>("Application.CameraManager", 1, 0, "CameraManager", service.get());
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    QObject *obj;
    AppEnginer *mAppEnginer=new AppEnginer(obj,mCameramanager);
    return app.exec();
}

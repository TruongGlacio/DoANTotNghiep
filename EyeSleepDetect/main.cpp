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
   // QScopedPointer<QString> serviceGetImage((mCameramanager->ImagePathForView()));
    qmlRegisterSingletonInstance<CameraManager>("Application.CameraManager", 1, 0, "CameraManager", service.get());
   // qmlRegisterSingletonType<QString>,("Application.CameraManager", 1, 0, "ImagePathForView",mCameramanager->mImagepathForView );
    qmlRegisterTypeNotAvailable("Application.CameraManager", 1, 0, "ImagePathForView", mCameramanager->mImagepathForView);

    QQmlApplicationEngine engine;
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

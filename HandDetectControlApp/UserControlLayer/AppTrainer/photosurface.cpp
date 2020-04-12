#include "photosurface.h"

Photosurface::Photosurface(QObject *parent) : QObject(parent)
{
    QQuickWindow::setDefaultAlphaBuffer(true);

     QCoreApplication::setApplicationName(QStringLiteral("Photosurface"));
     QCoreApplication::setOrganizationName(QStringLiteral("QtProject"));
     QCoreApplication::setApplicationVersion(QLatin1String(QT_VERSION_STR));

     QQmlApplicationEngine engine;
     QQmlContext *context = engine.rootContext();

     QUrl picturesLocationUrl = QUrl::fromLocalFile(QDir::homePath());
     const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
     context->setContextProperty(QStringLiteral("contextPicturesLocation"), picturesLocationUrl);

     engine.load(QUrl("qrc:///photosurface.qml"));
     if (engine.rootObjects().isEmpty())
         return;

}

QStringList Photosurface::imageNameFilters()
{
    QStringList result;
    QMimeDatabase mimeDatabase;
    const auto supportedMimeTypes = QImageReader::supportedMimeTypes();
    for (const QByteArray &m : supportedMimeTypes) {
        const auto suffixes = mimeDatabase.mimeTypeForName(m).suffixes();
        for (const QString &suffix : suffixes)
            result.append(QLatin1String("*.") + suffix);
    }
    return result;
}

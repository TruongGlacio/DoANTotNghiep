#ifndef PHOTOSURFACE_H
#define PHOTOSURFACE_H

#include <QObject>
//#ifdef QT_WIDGETS_LIB
//#include<QApplication>
//#include <QtWidgets/QApplication>
//#else
//#include <QtGui/QGuiApplication>
//#endif
#include<QApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlContext>
#include <QtQuick/QQuickWindow>
#include <QtGui/QImageReader>
#include <QtCore/QCommandLineParser>
#include <QtCore/QCommandLineOption>
#include <QtCore/QDebug>
#include <QtCore/QDir>
#include <QtCore/QMimeDatabase>
#include <QtCore/QStandardPaths>
#include <QtCore/QUrl>
class Photosurface : public QObject
{
    Q_OBJECT
public:
    explicit Photosurface(QObject *parent = nullptr);
    static QStringList imageNameFilters();

signals:


};

#endif // PHOTOSURFACE_H

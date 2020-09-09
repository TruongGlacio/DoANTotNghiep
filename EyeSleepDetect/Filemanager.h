#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include<QFileDialog>
#include"GlobalFile.h"
class FileManager : public QObject
{
    Q_OBJECT
public:
    explicit FileManager(QObject *parent = nullptr);

public slots:
    void GetListImageFromFileBroswer();



signals:
    void SendUpdateCurrentIndex(int currentIndex);
    void SendUpdateFolderPath(QString folderPath);

};

#endif // FILEMANAGER_H

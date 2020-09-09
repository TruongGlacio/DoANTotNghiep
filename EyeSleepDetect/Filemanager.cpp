#include "Filemanager.h"

FileManager::FileManager(QObject *parent) : QObject(parent)
{

}

void FileManager::GetListImageFromFileBroswer()
{
    FUNCTION_LOG();

    // QWidget *widget=new QWidget();
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::Directory);
    dialog.setOption(QFileDialog::ShowDirsOnly);
    //int result = dialog.exec();
    QString directory;
    directory = dialog.getExistingDirectory(0,"Caption",QString(), dialog.ShowDirsOnly);

    QDir directoryImage(directory);

    QStringList imagesList = directoryImage.entryList(QStringList() << "*.jpg" << "*.JPG",QDir::Files);
    if(imagesList.size()<=0)
    {
        qDebug()<<"havn't any file in folder selected"<<endl;
        return;
    }
    qDebug()<<"havn any file in folder selected, the folder path="<<directory<<endl;
    int currentIndex=0;
    emit SendUpdateFolderPath(directory);
    emit SendUpdateCurrentIndex(currentIndex);
}

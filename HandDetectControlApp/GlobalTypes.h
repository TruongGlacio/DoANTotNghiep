#ifndef GLOBALTYPES_H
#define GLOBALTYPES_H
#include <QObject>
#include <QDate>
#include<QJsonValue>
#include<QPoint>
#include <QUrl>
#include <QJsonObject>

struct NewsInfo
{
    int id;
    QString src;
};


// struct config for people detect data
 /*-------------------------------------------------*/
 struct DectectData{
     QString event;
     QString source;
     QJsonValue data;
 };
 struct DectectHandData{
     QString event;
     QString source;
     QPoint box_center;
 };
 /*-------------------------------------------------*/

 // struct config for Company Data
 /*-------------------------------------------------*/
 struct CompanyData{
     QString name;
     QString createDate;
 };
 /*-------------------------------------------------*/

 // struct config for Customer Data
 /*-------------------------------------------------*/

 struct CustomerInfo
 {
     QString name;
     QString company;
     QString detail;
     QString visitDate;
     int duration;
 };

 struct CustomerData{
     QList<CustomerInfo> info;
     QString createDate;
 };
 /*-------------------------------------------------*/

 struct GuilineVideo{
     QString name;
     QString createDate;
 };

 // struct config for standby video
 /*-------------------------------------------------*/
 struct StandbyVideo{
     QString name;
     QString createDate;
 };
 /*-------------------------------------------------*/

 // struct config for ForFun Data
 /*-------------------------------------------------*/
 struct OtherInforData {
     QList<QString> data;
     QString createDate;
 };

 /*-------------------------------------------------*/

 // struct config for News Data
 /*-------------------------------------------------*/
 struct NewsData{
     QList<QString> data;
     QString createDate;
 };

 /*-------------------------------------------------*/


 // struct config for TechInfo Data
 /*-------------------------------------------------*/
 struct ConfigTechnologies{
     QString mainImagePath;
     QList<QString> aIInfo;
     QList<QString> iOTInfo;
     QList<QString> cloudInfo;
     QList<QString> embeddedInfo;
     QString createDate;

 };
 /*-------------------------------------------------*/

 // struct config for UpdateStatus Data
 /*-------------------------------------------------*/
 struct UpdateStatusData{
     bool newsInfo;
     bool customerInfo;
     bool othersScreenInfo;
     bool techInfo;
     bool companyStructureInfo;
     bool standbyVideo;
     bool guidelineVideo;
 };
 /*-------------------------------------------------*/

 // struct config for genaral Json
 /*-------------------------------------------------*/
 struct GenaralJson{
     NewsData newsData;
     CompanyData companyData;
     CustomerData customerData;
     GuilineVideo guilineVideo;
     StandbyVideo standbyVideo;
     OtherInforData otherInforData;
     DectectData dectectData;
     DectectHandData dectectHandData;
     ConfigTechnologies configTechnologies;
     UpdateStatusData updateStatusData;
 };
 /*-------------------------------------------------*/

 // struct config for config info
 /*-------------------------------------------------*/
 struct ConfigData{
     QList<QString> newsInfo;
     QString companyStructureImagePath;
     ConfigTechnologies technologies;
     QList<CustomerInfo> customerInfo;
     QString standbyVideoPath;

     QString menuVideoPath;
     QList<QString> othersInfo;
 };
 struct Config{
     QString creatDate;
     ConfigData data;
 };
 /*-------------------------------------------------*/


struct Technologies{
        QString mainImagePath;
        QList<QString> aIInfo;
        QList<QString> iOTInfo;
        QList<QString> cloudInfo;
        QList<QString> embeddedInfo;
};

// List data use for compare update
struct CompareData {
    QString folder;
    QUrl api;
};

// List data use for update
struct DataDownload {
    QJsonObject jsonDownload;
    QString folderSave;
    bool isDownloadFalse = false;
    QString CreateDate = "";
};

struct FileDownload {
    QString apiPath;
    QString folderSave;
    QString newFolder;
};

struct APIDownloadInfo {
    QList<QString> listPathName;
    QString createDate;
};

#endif // GLOBALTYPES_H

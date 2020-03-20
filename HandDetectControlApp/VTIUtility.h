#ifndef VTIUTILITY_H
#define VTIUTILITY_H

#include <QObject>
#include<QPoint>
#include <QDateTime>
#include <GlobalTypes.h>
#include <QJsonObject>

class VTIUtility : public QObject
{
    Q_OBJECT
public:
    explicit VTIUtility(QObject *parent = nullptr);
    static bool CopyRecursively(QString sourceFolder, QString destFolder);
    static QJsonObject ReadJsonDataFile(QString filepath);
    static void WriteJsonFile(QString data ,QString filepath);
    static DectectData ReadDectectDataJson(QJsonObject jsonObject);
    static DectectHandData ReadDectectHandDataJson( QJsonObject jsonObject);
    static CompanyData ReadCompanyDataJson(QJsonObject jsonObject);
    static CustomerData ReadCustomerDataJson(QJsonObject jsonObject);
    static GuilineVideo ReadGuilineVideoDataJson(QJsonObject jsonObject);
    static StandbyVideo ReadStandbyVideoDataJson(QJsonObject jsonObject);
    static OtherInforData ReadOtherInfoJsonJson(QJsonObject jsonObject);
    static NewsData ReadNewsDataJson(QJsonObject jsonObject);
    static ConfigTechnologies ReadTechInfoDataJson(QJsonObject jsonObject);
    static UpdateStatusData ReadUpdateStatusDataJson(QJsonObject jsonObject);
    static Config ReadConfigDataJson(QString filepath);
    static void WriteConfigDataJson(Config config, QString filepath);

signals:

public slots:

};

#endif // VTIUTILITY_H

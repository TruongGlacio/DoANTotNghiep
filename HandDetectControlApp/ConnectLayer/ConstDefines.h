#ifndef CONSTDEFINES_H
#define CONSTDEFINES_H
#define CAM_WIDTH 640
#define CAM_HEIGHT 480
#define DESKTOP_PIXEL_WIDTH 1366
#define DESKTOP_PIXEL_HEIGHT 768
//#define OBJ_APP_ENGINE                      "AppEngine"
//#define OBJ_SCREEN_MANAGER                  "ScreenManager"
//#define OBJ_SCREEN_STANDBY_CONTROLLER       "StandbyController"
//#define OBJ_SCREEN_STANDBY_MODEL            "StandbyModel"
//#define PATH_VTISAYHI                       "/VTISayHi"
//#define OBJ_TECHSCR_MODEL                   "TechScrModel"
//#define OBJ_STARTSCR_MODEL                  "StartScrModel"
//#define OBJ_NEWSSCR_MODEL                   "NewsScrModel"
//#define OBJ_MENU_MODEL                      "MenuScrModel"
//#define OBJ_COMPANY_MODEL                   "CompanyScrModel"
//#define OBJ_FORFUN_MODEL                    "ForfunScrModel"
//#define OBJ_WELCOME_SCR_MODEL               "WelcomeScrModel"
//#define OBJ_TECHSCR_CONTROLLER              "TechScrController"
//#define OBJ_STARTSCR_CONTROLLER             "StartUpScrController"
//#define OBJ_NEWSSCR_CONTROLLER              "NewsScrController"
//#define OBJ_MENU_CONTROLLER                 "MenuScrController"
//#define OBJ_COMPANY_CONTROLLER              "CompanyScrController"
//#define OBJ_FORFUN_CONTROLLER               "ForfunScrController"
//#define OBJ_WELCOME_SCR_CONTROLLER          "WelcomeScrController"
//#define PATH_NEWS_DATA                      "/News/"
//#define PATH_COMPANY_STRUCTURE_DATA         "/CompanyStructure/"
//#define PATH_GUIDELINE_VIDEO_DATA           "/GuidelineVideo/"
//#define PATH_OTHERS_INFO_DATA               "/OthersInfo/"
//#define PATH_STANDBY_DATA                   "/StandbyVideo/"
//#define PATH_TECH_DATA                      "/Technologies/"
//#define PATH_CUSTOMER_INFO_DATA             "/CustomerInfo/"
//#define PATH_CONFIG                         "/Config.json"

#define CREATDATE   "createDate"
// DEFINE FOR DETECT JSON OBJECT
#define DETECT_EVENT "event"
#define DETECT_DATA "data"
#define DETECT_SOURCE "source"
#define DETECT_CLASS "class"
#define DETECT_SCORE "score"
#define DETECT_BOX "box"
#define DETECT_BOX_CENTRER "box_center"
#define DETECT_FACE "face"
#define DETECT_HAND "hand"
#define DETECT_DETECTED "detected"
#define DETECT_NO_DETECTED "no_detected"
#define DETECT_X 0
#define DETECT_Y 1
#define DETECT_CLIENT_CONNECTED "Client connected"
#define DETECT_SEND_DETECT_RESULT 0
#define DETECT_SEND_LOCATION 1

//DEFINE FOR COMPANYSTRUCTURE JSON OBJECT

#define COMPANY_NAME "name"
#define COMPANY_CREATDATE CREATDATE

//DEFINE FOR CUSTOMER INFO JSON OBJECT

#define CUSTOMER_DATA "data"
#define CUSTOMER_NAME "name"
#define CUSTOMER_COMPANY "company"
#define CUSTOMER_DETAIL "detail"
#define CUSTOMER_VISITDATE "visitDate"
#define CUSTOMER_DURATION "duration"
#define CUSTOMER_CREATDATE CREATDATE

//define for Guiline video json
#define GUILINE_NAME "name"
#define GUILINE_CREATDATE CREATDATE

//DEFINE FOR other info JSON OBJECT
#define FORFUN_DATA "data"
#define FORFUN_CREATDATE CREATDATE

//DEFINE FOR NEWS JSON OBJECT
#define NEWS_DATA "data"
#define NEWS_CREATDATE CREATDATE

//define for standby video json object

#define STANDBY_VIDEO_NAME "name"
#define STANDBY_VIDEO_CREATDATE CREATDATE

// DEFINE FOR TECHINFO JSON OBJECT

#define TECHINFO_DATA "data"
#define TECHINFO_IMAGEPATH "mainImagePath"
#define TECHINFO_AI "AIInfo"
#define TECHINFO_IOT "IOTInfo"
#define TECHINFO_CLOUD "CloudInfo"
#define TECHINFO_EMBEDDED "EmbeddedInfo"
#define TECHINFO_CREATDATE CREATDATE

//DEFINE FOR UPDATE STATUS JSON OBJECT

#define UPDATESTATUS_NEWSINFO "NewsInfo"
#define UPDATESTATUS_CUSTOMERINFO "CustomerInfo"
#define UPDATESTATUS_OTHERSSCREENINFO "OthersScreenInfo"
#define UPDATESTATUS_TECHINFO "TechInfo"
#define UPDATESTATUS_COMPANYSTRUCTUREINFO "CompanyStructureInfo"
#define UPDATESTATUS_STANDBYVIDEO "StandbyVideo"
#define UPDATESTATUS_GUIDELINEVIDEO "GuidelineVideo"

// define FOR CONFIG JSON OBJECT
#define CONFIG_FILENAME "E:/VTISayHi/Document/vtisayhidoc/01_Requirement/DataSample/config1.json"
#define CONFIG_CREATDATE CREATDATE
#define CONFIG_DATA_NEWS "NewsInfo"
#define CONFIG_DATA_COMPANYSTRUCTURE "CompanyStructureInfo"
#define CONFIG_DATA_TECHNOLOGIES "TechnologiesInfo"
#define CONFIG_DATA_TECHNOLOGIES_IMAGEPATH TECHINFO_IMAGEPATH
#define CONFIG_DATA_TECHNOLOGIES_AI TECHINFO_AI
#define CONFIG_DATA_TECHNOLOGIES_IOT TECHINFO_IOT
#define CONFIG_DATA_TECHNOLOGIES_CLOUD TECHINFO_CLOUD
#define CONFIG_DATA_TECHNOLOGIES_EMBEDDED TECHINFO_EMBEDDED
#define CONFIG_DATA_CUSTOMERINFO "CustomerInfo"
#define CONFIG_DATA_STANDBYVIDEO "StandbyVideoInfo"
#define CONFIG_DATA_MENU_VIDEO "MenuVideoInfo"
#define CONFIG_DATA_OTHERSINFO "OthersInfo"
#define CONFIG_DATA_NAME "name"
#define CONFIG_DATA_COMPANY "company"
#define CONFIG_DATA_DETAIL "detail"
#define CONFIG_DATA_VISITDATE "visitDate"
#define CONFIG_DATA_DURATION "duration"

#define CONFIG_TIMEOUT_DETECT_PEOPLE 5000
#define CONFIG_TIMEOUT_SHOW_CUS_WELCOME_SCREEN 5000
#define CONFIG_FILE_COMPARE_UPDATE "CompareUpdate.json"
#define CONFIG_FILE_TAIL_RAW "_raw"
#define CONFIG_TIME_CHECKUPDATE 54000
#define CONFIG_RETURN_TYPE "application/json"
#define CONFIG_HEADER_AUTHOR "Authorization"
#define CONFIG_HEADER_TOKEN "Bearer "
#define CONFIG_JSON_TOKEN "token"
#define CONFIG_JSON_SUCCESS "success"
#define CONFIG_JSON_CREATE_DATE "createDate"

#include <QString>
#include <QUrl>

const QString DEFAULT_ADDRESS_WEBSERVER= "wss://localhost:8000";//"http://localhost:8000";
const QString API_NEWS = DEFAULT_ADDRESS_WEBSERVER + "/api/news";
const QString API_CUSTOMER = DEFAULT_ADDRESS_WEBSERVER + "/api/welcome";
const QString API_GUIDELINE = DEFAULT_ADDRESS_WEBSERVER + "/api/guideline";
const QString API_OTHERS = DEFAULT_ADDRESS_WEBSERVER + "/api/forfuns";
const QString API_STANDBY = DEFAULT_ADDRESS_WEBSERVER + "/api/standby";
const QString API_TECH = DEFAULT_ADDRESS_WEBSERVER + "/api/technologies";
const QString USERNAME = "Tam";
const QString PASSWORD = "123456";
const QUrl APP_SIGNIN = DEFAULT_ADDRESS_WEBSERVER + "/api/login?name=" + USERNAME + "&password=" + PASSWORD;

#endif // CONSTDEFINES_H


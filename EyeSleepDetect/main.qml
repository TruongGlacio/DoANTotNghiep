import QtQuick 2.14
import QtQuick.Window 2.14
import QtMultimedia 5.14

import Application.CameraManager 1.0
import QtQuick.Controls 2.13

Window {
    id: mainWindow
    visible: true
    width: 640
    height: 530
    title: qsTr("Hello World")
    signal qmlStopCameraSignal()
    signal qmlStartCameraSignal()
    signal qmlSwitchImage(bool distance)


    CameraManager{

    }
    VideoOutput {
        id:viewTrackingVideo
        clip: false
        objectName: "videoOutput";
        anchors.fill: parent;
        anchors.bottomMargin: 50
        visible: true
        fillMode: VideoOutput.PreserveAspectCrop;
        source: CameraManager;//(radioButton_tracking.checked==true)? CameraManager : null;

    }
    RadioButton {
        id: radioButton_tracking
        x: 260
        y: 494
        width: 60
        height: 30
        text: qsTr("")
        checked: true
        onClicked: {
            if(radioButton_tracking.checked==false)
            {
                mainWindow.qmlStopCameraSignal()
                radioButton_tracking.text=qsTr("Stoped")
                viewTrackingVideo.source=null;
                viewTrackingVideo.visible=false;
                imageShow.visible=true;
                imageShow.source="qrc:/qtquickplugin/images/template_image.png"
                console.log("Stop camera");
            }
            else
            {
                mainWindow.qmlStartCameraSignal()
                radioButton_tracking.text=qsTr("Started")
                viewTrackingVideo.source=CameraManager;
                viewTrackingVideo.visible=true;
                imageShow.visible=false;
                console.log("Start camera");
            }
        }
        autoExclusive: false

    }
    Image {
        id: imageShow
        x: 8
        y: 8
        width: 624
        height: 480
        anchors.bottomMargin: 50
        fillMode: Image.PreserveAspectFit
        source:ImagePathForView
        visible: false
    }

    Button {
        id: buttonBack
        x: 211
        y: 494
        width: 50
        height: 30
        text: qsTr("Back")
        onClicked:
        {

            mainWindow.qmlSwitchImage(false)
            imageShow.source=ImagePathForView
        }
    }
    Button {
        id: buttonNext
        x: 317
        y: 494
        width: 50
        height: 30
        text: qsTr("Next")
        onClicked: mainWindow.qmlSwitchImage(true)

    }
}

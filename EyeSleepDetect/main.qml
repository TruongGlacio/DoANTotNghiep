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
        width: 83
        height: 30
        text: qsTr("Started")
        checked: true
        onClicked: {
            if(radioButton_tracking.checked==false)
            {
                mainWindow.qmlStopCameraSignal()
                radioButton_tracking.text=qsTr("Stoped")
                viewTrackingVideo.source=CameraManager;
                buttonBack.visible=true
                buttonNext.visible=true
                console.log("Stop camera");
            }
            else
            {
                mainWindow.qmlStartCameraSignal()
                radioButton_tracking.text=qsTr("Started")
                viewTrackingVideo.source=CameraManager;
                buttonBack.visible=false
                buttonNext.visible=false
                console.log("Start camera");
            }
        }
        autoExclusive: false

    }

    Button {
        id: buttonBack
        x: 174
        y: 494
        width: 50
        height: 30
        text: qsTr("Back")
        visible: false
        onClicked:
        {
            mainWindow.qmlSwitchImage(false)
        }
    }
    Button {
        id: buttonNext
        x: 371
        y: 494
        width: 50
        height: 30
        visible: false
        text: qsTr("Next")
        onClicked:
        {mainWindow.qmlSwitchImage(true)}

    }
}

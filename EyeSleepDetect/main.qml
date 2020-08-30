
import QtQuick 2.11
import QtQuick.Window 2.4
import QtMultimedia 5.11
import QtQuick.Controls 2.4

/*comment import lib if system is linux*///Qt.platform.os == "linux"

//import Application.CameraManager 1.0;

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
        source: CameraManager;

    }

    Column {
        id: column
        x: 157
        y: 482
        width: 262
        height: 41
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 10
        anchors.bottom: parent.bottom
        RadioButton {
            id: radioButton_tracking
            x: 260
            y: 494
            width: 83
            height: 30
            text: qsTr("Started")
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
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
            y: 494
            width: 50
            height: 30
            text: qsTr("Back")
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 10
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
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 10
            onClicked:
            {mainWindow.qmlSwitchImage(true)}

        }
    }


}

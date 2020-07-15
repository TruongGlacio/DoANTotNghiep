import QtQuick 2.14
import QtQuick.Window 2.14
import QtMultimedia 5.14

import Application.CameraManager 1.0
import QtQuick.Controls 2.13

Window {
    visible: true
    width: 640
    height: 530
    title: qsTr("Hello World")

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
    RadioButton {
        id: radioButton_tracking
        x: 255
        y: 494
        width: 111
        height: 32
        text: qsTr("StartTracking")
        checked: false
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
        //source: "qrc:/qtquickplugin/images/template_image.png"
        visible: false
    }
}

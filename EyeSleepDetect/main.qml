
import QtQuick 2.11
import QtQuick.Window 2.4
import QtMultimedia 5.11
import QtQuick.Controls 2.4

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 840
    height: 530
    color: mainWindow.color
    title: qsTr("Hello World")

    signal qmlStopCameraSignal()
    signal qmlStartCameraSignal()
    signal qmlSendThresholdValue(int value)
    signal qmlSendThresholdType(int typeValue)
    signal qmlSwitchImage(bool distance)
    signal qmlFileBroswer()
    VideoOutput {
        id:viewTrackingVideo
        rotation: 0
        z: 23.37
        anchors.topMargin: 50
        anchors.rightMargin: 200
        anchors.leftMargin: 5
        clip: false
        objectName: "videoOutput";
        anchors.fill: parent;
        anchors.bottomMargin: 50
        visible: true
        fillMode: VideoOutput.Stretch ;
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

    Column {
        id: column1
        x: 646
        width: 190
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 50
        anchors.right: parent.right
        anchors.rightMargin: 5
        anchors.top: parent.top
        anchors.topMargin: 0


        Row {
            id: row
            width: 140
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 50

            ComboBox {
                id: comboBox
                height: 30
                focusPolicy: Qt.ClickFocus
                flat: false
                displayText: qsTr(comboBox.currentText)
                editable: false
                layer.smooth: true
                clip: true
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: 8
                anchors.top: parent.top
                anchors.topMargin: 50
                model:
                    ListModel {
                    ListElement { text: qsTr("THRESH_BINARY") }//Binary
                    ListElement { text:qsTr ("THRESH_BINARY_INV") }//BinaryInverted
                    ListElement { text: qsTr("THRESH_TRUNC") }//Truncate
                    ListElement { text: qsTr("THRESH_TOZERO") }//ToZero
                    ListElement { text: qsTr("THRESH_TOZERO_INV") }//ToZeroInverted
                    ListElement { text: qsTr("THRESH_MASK") }//
                    ListElement { text: qsTr("THRESH_OTSU") }//
                    ListElement { text: qsTr("THRESH_TRIANGLE") }//
                }

                onActivated:{
                    if(comboBox.currentIndex<=3)
                    {
                        mainWindow.qmlSendThresholdType(comboBox.currentIndex+1)
                    }
                    else
                    {
                        if(comboBox.currentIndex==4||comboBox.currentIndex==5)
                            mainWindow.qmlSendThresholdType(comboBox.currentIndex+3)
                        else
                        {
                            mainWindow.qmlSendThresholdType(16)
                        }
                    }

                    comboBox.displayText= qsTr(comboBox.currentText)
                }

            }
        }

        Column {
            id: column2
            width: 40
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 10
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 50

            Slider {
                id: slider_ThresHoldingValue
                width: 23

                snapMode: "NoSnap"
                anchors.top: parent.top
                anchors.topMargin: 0
                anchors.right: parent.right
                anchors.rightMargin: 10
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
                stepSize: 1
                to: 255
//                onActiveFocusChanged: {
//                    mainWindow.qmlSendThresholdValue(slider_ThresHoldingValue.value)
//                    element.text=slider_ThresHoldingValue.value
//                }

                onValueChanged: {
                    mainWindow.qmlSendThresholdValue(slider_ThresHoldingValue.value)
                    element.text=slider_ThresHoldingValue.value
                }
                orientation: Qt.Vertical
                value: 0
            }
        }

        Text {
            id: element
            width: 39
            height: 23
            text: qsTr("0")
            anchors.top: column2.bottom
            anchors.topMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 10
            textFormat: Text.RichText
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 14
        }

        Text {
            id: element1
            width: 94
            height: 23
            text: qsTr("Threshold Value:")
            anchors.top: column2.bottom
            anchors.topMargin: 5
            anchors.right: element.left
            anchors.rightMargin: 5
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 12
        }

    }

    Column {
        id: column3
        height: 45
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 200
        anchors.top: parent.top
        anchors.topMargin: 5

        Button {
            id: buttonFileBroswer
            width: 60
            height: 30
            text: qsTr(".....")
            clip: false
            layer.wrapMode: ShaderEffectSource.ClampToEdge
            layer.smooth: true
            padding: 10
            rotation: 0
            z: 100
            scale: 1
            font.bold: true
            font.underline: false
            transformOrigin: Item.Center
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 8
            anchors.right: parent.right
            anchors.rightMargin: 5
            anchors.top: parent.top
            anchors.topMargin: 8
            onClicked: {
                mainWindow.qmlFileBroswer()
            }
        }

        Rectangle {
            color: "#00000000"
            opacity: 1
            border.width: 2
            radius: 2
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 8
            anchors.top: parent.top
            anchors.topMargin: 8
            anchors.right: parent.right
            anchors.rightMargin: 80
            anchors.left: parent.left
            anchors.leftMargin: 10

            TextEdit {
                id: textEdit_FolderPath
                x: 10
                y: 13
                height: 30
                text: CameraManager.folderPath
                layer.enabled: true
                layer.wrapMode: ShaderEffectSource.RepeatHorizontally
                layer.smooth: true
                clip: true
                wrapMode: Text.NoWrap
                textFormat: Text.AutoText
                z: 64.674
                layer.effect: column3
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.right: parent.right
                anchors.rightMargin: 5
                anchors.verticalCenter: parent.verticalCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 12
                selectByMouse: true
                //background
            }
        }
    }




}

/*##^##
Designer {
    D{i:5;anchors_height:496;anchors_width:184;anchors_x:646;anchors_y:24}D{i:9;anchors_height:400;anchors_y:0}
D{i:10;anchors_height:369}D{i:11;anchors_height:23}D{i:12;anchors_height:23}D{i:8;anchors_height:400;anchors_y:0}
D{i:7;anchors_height:398;anchors_y:0}D{i:18;anchors_width:45;anchors_x:11;anchors_y:0}
D{i:6;anchors_height:496;anchors_width:184;anchors_x:646;anchors_y:24}D{i:20;anchors_height:30;anchors_width:80}
D{i:22;anchors_width:80}D{i:21;anchors_height:20;anchors_width:80}D{i:19;anchors_height:30;anchors_width:45;anchors_x:11;anchors_y:0}
}
##^##*/

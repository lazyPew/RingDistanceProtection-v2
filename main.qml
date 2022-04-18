import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.VirtualKeyboard 2.2

import "Pages"

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Stack")

    header: ToolBar {
        contentHeight: toolButton.implicitHeight

        ToolButton {
            id: toolButton
            text: "\u2630"
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            onClicked: {
                drawer.open()
            }
        }

        Label {
            text: stackView.currentItem.title
            anchors.centerIn: parent
        }
    }

    Drawer {
        id: drawer
        width: window.width * 0.66
        height: window.height

        Column {
            anchors.fill: parent

            ItemDelegate {
                text: qsTr("Мнемосхема")
                width: parent.width
                onClicked: {
                    stackView.pop()
                    stackView.push("Pages/MainPage.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("Параметры системы")
                width: parent.width
                onClicked: {
                    stackView.pop()
                    stackView.push("Pages/ParametersPage.qml")
                    drawer.close()
                }
            }
        }
    }

    StackView {
        id: stackView
        initialItem: "Pages/MainPage.qml"
        anchors.fill: parent
    }

    InputPanel {
        id: inputPanel
        z: 99
        x: 0
        y: window.height
        width: window.width

        states: State {
            name: "visible"
            when: inputPanel.active
            PropertyChanges {
                target: inputPanel
                y: window.height - inputPanel.height
            }
        }
        transitions: Transition {
            from: ""
            to: "visible"
            reversible: true
            ParallelAnimation {
                NumberAnimation {
                    properties: "y"
                    duration: 250
                    easing.type: Easing.InOutQuad
                }
            }
        }
    }
}

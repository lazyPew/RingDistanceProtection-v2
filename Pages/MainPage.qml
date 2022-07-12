import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../Elements"

import DataModelTypes 1.0

Page {
    property var dpTerminals: []
    anchors.fill: parent

    title: qsTr("Мнемосхема подстанции")

    ColumnLayout {
        id: columnLayout
        width: 1250
        height: 700

        Rectangle {
            id: rectangle
            color: "#00000000"
            border.width: 4
            Layout.fillHeight: true
            Layout.fillWidth: true
            border.color: "#00000000"

            Image{
                anchors.fill: parent
                Layout.fillHeight: true
                Layout.fillWidth: true
                source: "Images/scheme.png"
                fillMode: Image.PreserveAspectFit
            }

            Repeater{
                id: dpRepeater
                model:[
                    { x: 463, y: 98, w:48, h:63 },
                    { x: 513, y: 253, w:61, h:47 },
                    { x: 658, y: 249, w:61, h:50 },
                    { x: 718, y: 99, w:48, h:61 },
                    { x: 713, y: 12, w:48, h:60 },
                    { x: 466, y: 7, w:48, h:66 }
                ]

                DPTerminalButton{
                    x: modelData.x
                    y: modelData.y
                    width: modelData.w
                    height: modelData.h
                    terminal: panel.substation.functionObj.getTerminalByIndex(index)
                }
            }

            Repeater{
                id: sRepeater
                x: -5
                y: -2
                model:[
                    { x:356, y:42, w:55, h:55 },
                    { x:804, y:43, w:57, h:55 },
                ]
                AbstractButton{
                    x: modelData.x
                    y: modelData.y
                    width: modelData.w
                    height: modelData.h
                    background: Rectangle {
                        color: "#00000000"
                        id: s1rect
                        radius: 44
                        border.color: "#ffffff"

                    }
                    MouseArea {
                        id: mouseArea
                        anchors.fill: parent
                        onClicked:{
                            console.log(index)
                            console.log(panel.substation.functionObj.equipment.getSystemByIndex(index).name)
                        }
                    }
                }
            }

            Rectangle {
                id: b5rect
                x: 510
                y: 505
                width: 209
                height: 7
                color: "#ffffff"
            }

            Rectangle {
                id: b4rect
                x: 753
                y: 312
                width: 7
                height: 183
                color: "#ffffff"
            }

            Rectangle {
                id: b3rect
                x: 519
                y: 307
                width: 178
                height: 6
                color: "#ffffff"
            }

            Rectangle {
                id: b2rect
                x: 789
                y: 39
                width: 7
                height: 109
                color: "#ffffff"
                border.color: "#ffffff"
            }

            Rectangle {
                id: b1rect
                x: 424
                y: 43
                width: 7
                height: 89
                color: "#ffffff"
                border.color: "#ffffff"
            }

            Rectangle {
                id: t1rect
                x: 497
                y: 316
                width: 135
                height: 138
                color: "#00000000"
                border.color: "#00000000"
                Rectangle {
                    id: t1hvrect
                    x: 38
                    y: 38
                    width: 55
                    height: 55
                    color: "#00000000"
                    radius: 44
                    border.color: "#ffffff"
                }

                Rectangle {
                    id: t1lvrect
                    x: 40
                    y: 67
                    width: 56
                    height: 55
                    color: "#00000000"
                    radius: 44
                    border.color: "#ffffff"
                }

                Rectangle {
                    id: t1mvrect
                    x: 67
                    y: 50
                    width: 55
                    height: 53
                    color: "#00000000"
                    radius: 44
                    border.color: "#ffffff"
                }

                MouseArea {
                    id: t1mouse1
                    width: 56
                    height: 44
                }

                MouseArea {
                    id: t1mouse2
                    x: 35
                    y: 36
                    width: 88
                    height: 89
                }
            }

            Rectangle {
                id: t2rect
                x: 611
                y: 319
                width: 135
                height: 138
                color: "#00000000"
                Rectangle {
                    id: t2hvrect
                    x: 35
                    y: 35
                    width: 53
                    height: 56
                    color: "#00000000"
                    radius: 44
                    border.color: "#ffffff"
                }

                Rectangle {
                    id: t2lvrect
                    x: 36
                    y: 64
                    width: 55
                    height: 56
                    color: "#00000000"
                    radius: 44
                    border.color: "#ffffff"
                }

                Rectangle {
                    id: t2mvrect
                    x: 64
                    y: 48
                    width: 55
                    height: 51
                    color: "#00000000"
                    radius: 44
                    border.color: "#ffffff"
                }

                MouseArea {
                    id: t2mouse1
                    width: 58
                    height: 36
                }

                MouseArea {
                    id: t2mouse2
                    x: 32
                    y: 36
                    width: 91
                    height: 85
                }
                border.color: "#00000000"
            }

            Rectangle {
                id: l3rect
                x: 164
                y: 25
                width: 120
                height: 39
                color: "#00000000"
                border.color: "#00000000"

                MouseArea {
                    id: l3mouse1
                    x: 0
                    y: -10
                    width: 120
                    height: 9
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.rightMargin: 0
                    anchors.top: parent.top
                    anchors.topMargin: 4
                }

                MouseArea {
                    id: l3mouse2
                    x: 0
                    y: 19
                    width: 30
                    height: 20
                    anchors.bottom: parent.bottom
                    anchors.top: l3mouse1.bottom
                    anchors.topMargin: 4
                    anchors.leftMargin: 42
                    anchors.left: parent.left
                }
            }

            Rectangle {
                id: l2rect
                x: 666
                y: 101
                width: 77
                height: 149
                color: "#00000000"
                rotation: 0
                MouseArea {
                    id: l2mouse1
                    x: 34
                    y: 70
                    width: 40
                    height: 35
                }

                MouseArea {
                    id: l2mouse2
                    x: 16
                    y: 3
                    width: 10
                    height: 145
                    rotation: 10
                }

                Rectangle {
                    id: l2rectForm
                    x: 19
                    y: 6
                    width: 4
                    height: 140
                    color: "#ffffff"
                    radius: 2
                    rotation: 10.5
                    border.width: 0
                }
                border.color: "#00000000"
            }

            Rectangle {
                id: l1rect
                x: 472
                y: 101
                width: 97
                height: 145
                color: "#00000000"
                border.color: "#00000000"

                MouseArea {
                    id: l1mouse1
                    x: 7
                    y: 69
                    width: 33
                    height: 37
                }

                MouseArea {
                    id: l1mouse2
                    x: 67
                    y: 1
                    width: 10
                    height: 145
                    rotation: -17
                }

                Rectangle {
                    id: l1rectForm
                    x: 71
                    y: 3
                    width: 4
                    height: 140
                    color: "#ffffff"
                    radius: 2
                    border.width: 0
                    rotation: -17
                }
            }

        }

        Label{
            text: "Выбор конфигурации системы"
            Layout.fillHeight: false
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.fillWidth: false
            font.pixelSize: 15
        }

        RowLayout{
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.fillWidth: true

            Repeater{
                model:2
                Button{
                    text: index+1
                    font.pixelSize: 15
                    onClicked: {
                        panel.readFiles(index+1)
                    }
                }
            }
        }

        Button{
            text: "Рассчитать параметры срабатывания РЗ"
            font.pixelSize: 15
            Layout.alignment: Qt.AlignHCenter
            font.capitalization: Font.Capitalize
            onClicked: {
                panel.calculateProtectionParameters()
            }
        }

    }

    Component.onCompleted: {
        dpTerminals = panel.substation.functionObj.terminalsList
    }
}

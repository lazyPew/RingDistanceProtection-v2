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
                source: "Images/schemeUpd.png"
                fillMode: Image.PreserveAspectFit

                Rectangle {
                    id: t2mvrect
                    x: 675
                    y: 367
                    width: 55
                    height: 51
                    color: "#00000000"
                    radius: 44
                    border.color: "#ffffff"
                }

                Rectangle {
                    id: t2lvrect
                    x: 647
                    y: 383
                    width: 55
                    height: 56
                    color: "#00000000"
                    radius: 44
                    border.color: "#ffffff"
                }

                Rectangle {
                    id: t2hvrect
                    x: 646
                    y: 354
                    width: 53
                    height: 56
                    color: "#00000000"
                    radius: 44
                    border.color: "#ffffff"
                }

                Rectangle {
                    id: t1mvrect
                    x: 564
                    y: 366
                    width: 55
                    height: 53
                    color: "#00000000"
                    radius: 44
                    border.color: "#ffffff"
                }

                Rectangle {
                    id: t1lvrect
                    x: 537
                    y: 383
                    width: 56
                    height: 55
                    color: "#00000000"
                    radius: 44
                    border.color: "#ffffff"
                }

                Rectangle {
                    id: t1hvrect
                    x: 535
                    y: 354
                    width: 55
                    height: 55
                    color: "#00000000"
                    radius: 44
                    border.color: "#ffffff"
                }





            }

            Repeater{
                id: dpRepeater
                model:[
                    { x: 463, y: 98, w:48, h:63 },
                    { x: 513, y: 253, w:61, h:47 },
                    { x: 658, y: 249, w:61, h:50 },
                    { x: 718, y: 99, w:48, h:61 },
                    { x: 713, y: 10, w:48, h:60 },
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
                    { x:298, y:39, w:117, h:62 },
                    { x:802, y:39, w:119, h:62 },
                ]
                AbstractButton{
                    x: modelData.x
                    y: modelData.y
                    width: modelData.w
                    height: modelData.h
                    background: Rectangle {
                        id: sBckg
                        radius: 2
                        scale: sMouseArea.containsPress ? 0.95 : 1
                        opacity: sMouseArea.containsMouse ? 0.3 : 0.05

                    }
                    MouseArea {
                        id: sMouseArea
                        hoverEnabled: true
                        anchors.fill: parent
                        onClicked:{
                            equipmentPopup.eqObject = panel.substation.functionObj.equipment.getSystemByIndex(index)
                            equipmentPopup.open()
                        }
                    }
                }
            }

            Repeater{
                id: tRepeater
                model:[
                    { x:512, y:317, w:106, h:124 },
                    { x:619, y:316, w:112, h:124 }
                ]
                AbstractButton{
                    x: modelData.x
                    y: modelData.y
                    width: modelData.w
                    height: modelData.h
                    background: Rectangle {
                        id: tBckg
                        radius: 2
                        scale: tMouse.containsPress ? 0.98 : 1
                        opacity: tMouse.containsMouse ? 0.3 : 0.05

                        MouseArea {
                            id: tMouse
                            anchors.fill: parent
                            onClicked: {
                                equipmentPopup.eqObject = panel.substation.getTransformerByIndex(index)
                                equipmentPopup.open()
                            }
                        }
                    }
                }
            }

            Rectangle {
                id: l3rect
                x: 506
                y: 50
                width: 215
                height: 51
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
                    x: 70
                    y: 13
                    width: 60
                    height: 36
                }
            }

            Rectangle {
                id: l2rect
                x: 666
                y: 101
                width: 93
                height: 149
                color: "#00000000"
                rotation: 0
                MouseArea {
                    id: l2mouse1
                    x: 34
                    y: 76
                    width: 58
                    height: 36
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
                    y: 76
                    width: 61
                    height: 40
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

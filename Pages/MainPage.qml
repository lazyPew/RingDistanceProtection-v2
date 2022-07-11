import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

import "../Elements"

Page {
    width: 600
    height: 400

    property var dpTerminals: []

    title: qsTr("Мнемосхема подстанции")

    ColumnLayout {
        id: columnLayout
        x: 65
        y: 0
        width: 470
        height: 400

        Image{
            Layout.fillHeight: true
            Layout.fillWidth: true
            source: "Images/scheme.png"
            fillMode: Image.PreserveAspectFit

            // systems

            Rectangle {
                id: s1rect
                x: 71
                y: 26
                width: 34
                height: 33
                color: "#00000000"
                radius: 44
                border.color: "#ffffff"

                MouseArea {
                    id: mouseArea
                    anchors.fill: parent
                }
            }

            Rectangle {
                id: s2rect
                x: 344
                y: 27
                width: 34
                height: 33
                color: "#00000000"
                radius: 44
                border.color: "#ffffff"

                MouseArea {
                    id: mouseArea1
                    anchors.fill: parent
                    onClicked: {

                    }
                }
            }

            // WLines

            Rectangle {
                id: l1rect
                x: 146
                y: 72
                width: 56
                height: 77
                color: "#00000000"
                border.color: "#00000000"

                MouseArea {
                    id: l1mouse1
                    x: 0
                    y: 31
                    width: 20
                    height: 23
                }

                MouseArea {
                    id: l1mouse2
                    x: 36
                    y: -9
                    width: 8
                    height: 86
                    rotation: -17
                }

                Rectangle {
                    id: l1rectForm
                    x: 39
                    y: -9
                    width: 2
                    height: 86
                    color: "#ffffff"
                    radius: 1
                    border.width: 0
                    rotation: -17
                }
            }

            Rectangle {
                id: l2rect
                x: 252
                y: 68
                width: 57
                height: 77
                color: "#00000000"
                rotation: 0
                MouseArea {
                    id: l2mouse1
                    x: 28
                    y: 35
                    width: 25
                    height: 23
                }

                MouseArea {
                    id: l2mouse2
                    x: 16
                    y: -3
                    width: 8
                    height: 86
                    rotation: 10
                }

                Rectangle {
                    id: l2rectForm
                    x: 19
                    y: -3
                    width: 2
                    height: 86
                    color: "#ffffff"
                    radius: 1
                    rotation: 10.5
                    border.width: 0
                }
                border.color: "#00000000"
            }

            Rectangle {
                id: l3rect
                x: 169
                y: 27
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

            // transformers

            Rectangle {
                id: t1rect
                x: 163
                y: 195
                width: 70
                height: 71
                color: "#00000000"
                border.color: "#00000000"

                Rectangle {
                    id: t1hvrect
                    x: 17
                    y: 20
                    width: 34
                    height: 33
                    color: "#00000000"
                    radius: 44
                    border.color: "#ffffff"
                }

                Rectangle {
                    id: t1mvrect
                    x: 18
                    y: 38
                    width: 34
                    height: 33
                    color: "#00000000"
                    radius: 44
                    border.color: "#ffffff"
                }

                Rectangle {
                    id: t1lvrect
                    x: 35
                    y: 27
                    width: 33
                    height: 33
                    color: "#00000000"
                    radius: 44
                    border.color: "#ffffff"
                }

                MouseArea {
                    id: t1mouse1
                    width: 26
                    height: 21
                }

                MouseArea {
                    id: t1mouse2
                    x: 16
                    y: 19
                    width: 53
                    height: 53
                }
            }

            Rectangle {
                id: t2rect
                x: 230
                y: 195
                width: 70
                height: 71
                color: "#00000000"
                Rectangle {
                    id: t2hvrect
                    x: 18
                    y: 20
                    width: 33
                    height: 34
                    color: "#00000000"
                    radius: 44
                    border.color: "#ffffff"
                }

                Rectangle {
                    id: t2lvrect
                    x: 18
                    y: 38
                    width: 34
                    height: 33
                    color: "#00000000"
                    radius: 44
                    border.color: "#ffffff"
                }

                Rectangle {
                    id: t2mvrect
                    x: 36
                    y: 27
                    width: 33
                    height: 32
                    color: "#00000000"
                    radius: 44
                    border.color: "#ffffff"
                }

                MouseArea {
                    id: t2mouse1
                    width: 31
                    height: 20
                }

                MouseArea {
                    id: t2mouse2
                    x: 17
                    y: 19
                    width: 53
                    height: 53
                }
                border.color: "#00000000"
            }

            // buses

            Rectangle {
                id: b1rect
                x: 112
                y: 25
                width: 4
                height: 52
                color: "#ffffff"
                border.color: "#ffffff"
            }

            Rectangle {
                id: b2rect
                x: 334
                y: 26
                width: 4
                height: 58
                color: "#ffffff"
                border.color: "#ffffff"
            }

            Rectangle {
                id: b3rect
                x: 186
                y: 186
                width: 88
                height: 4
                color: "#ffffff"
            }

            Rectangle {
                id: b4rect
                x: 313
                y: 189
                width: 4
                height: 113
                color: "#ffffff"
            }

            Rectangle {
                id: b5rect
                x: 172
                y: 306
                width: 114
                height: 4
                color: "#ffffff"
            }

            // distance Protection terminals

            Repeater{


                model:[
                    { x: 140, y: 60 },
                    { x: 168, y: 155 },
                    { x: 258, y: 155 },
                    { x: 293, y: 60 },
                    { x: 290, y: 7 },
                    { x: 138, y: 5 }
                ]

                DPTerminalButton{
                    x: modelData.x
                    y: modelData.y
                    terminal: panel.substation.functionObj.getTerminalByIndex(index)
//                    terminal: dpTerminals[index]
                }

//                Rectangle{
//                    x: modelData.x
//                    y: modelData.y
//                    width: 24
//                    height: 35
//                    color: "transparent"
//                    border.color: "#ffffff"
//                    border.width: 1

//                    MouseArea {
//                        property var terminal: dpTerminals[index]
//                        anchors.fill: parent
//                        onClicked: {
//                            console.log(dpTerminals)
//                            console.log(terminal)
//                            console.log(terminal.name)
//                            console.log(terminal.firstZ)
//    //                        protectionPopup.dpObject = terminals[index]

//                            protectionPopup.open()
//                        }
//                    }
//                }
            }
        }

        Button{
            text: "Рассчитать параметры срабатывания РЗ"
            font.pointSize: 12
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            font.capitalization: Font.Capitalize
            onClicked: panel.calculateProtectionParameters()
        }
    }
    Component.onCompleted: {
        dpTerminals = panel.substation.functionObj.terminalsList
    }
}

import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import QtQuick.Controls.Styles 1.4

import DataModelTypes 1.0

Popup {
    id:root
    width: 250
    height: column.height* 1.05
    closePolicy: Popup.NoAutoClose
    x: (window.width - width ) / 2
    y: (window.contentItem.height - height) / 2
    modal: true
    focus: true
    property var dpObject

    ColumnLayout{
        id: column
        Layout.fillHeight: true
        width: parent.width

        Label{
            id: nameLabel
            font.pixelSize: 15
            Layout.alignment: Qt.AlignHCenter
        }

        Repeater{
            id:repeater

            RowLayout{
                Layout.fillHeight: true
                Layout.fillWidth: true

                Label{
                    font.pixelSize: 15
                    Layout.alignment: Qt.AlignLeft
                    text: modelData.name
                }

                TextField{
                    font.bold: true
                    font.pixelSize: 15
                    Layout.fillWidth: true
                    placeholderText: (modelData.value < 0
                                      ? "Не рассчитано"
                                      : Math.round(modelData.value * 1000) / 1000)
                    horizontalAlignment: Qt.AlignRight
                    readOnly: true
                }

                Label{
                    Layout.preferredWidth: 20
                    font.pixelSize: 15
                    Layout.alignment: Qt.AlignRight
                    text: (modelData.value < 0
                           ? ""
                           : modelData.unit)
                }
            }
        }

        Button{
            text: "Закрыть"
            font.pixelSize: 15
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            font.capitalization: Font.Capitalize
            onClicked: close()
            height: 20
        }
    }

    onOpened:{
//        if(dpObject.index.startsWith("DP"))
        nameLabel.text = dpObject.fullName
        repeater.model = [
            { name: "Z I", value: dpObject.firstZ, unit: "Ом" },
            { name: "T I", value: dpObject.firstT, unit: "с" },
            { name: "Z II", value: dpObject.secondZ, unit: "Ом" },
            { name: "T II", value: dpObject.secondT, unit: "с" },
            { name: "Z III", value: dpObject.thirdZ, unit: "Ом" },
            { name: "T III", value: dpObject.thirdT, unit: "с" }
        ]
    }
//    String.prototype.startsWith = function(str){}
}

import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import QtQuick.Controls.Styles 1.4

import DataModelTypes 1.0

Popup {
    id:root
    width: column.implicitWidth * 1.12
    height: column.implicitHeight * 1.1
    closePolicy: Popup.NoAutoClose
    x: (window.width - width ) / 2
    y: (window.contentItem.height - height) / 2
    modal: true
    focus: true
    property var eqObject

    property var secondControlItem

    ColumnLayout{
        id:column
        Layout.fillWidth: true

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

    onOpened: {
        nameLabel.text = eqObject.fullName
        switch (eqObject.index[0]) {
        case ("S") :
            repeater.model = [
                { name: "Мощность S", value: eqObject.powerS, unit: "МВА" },
                { name: "X", value: eqObject.resistX, unit: "Ом" }
            ]
            break;
        case ("W") :
            repeater.model = [
                { name: "Длина l", value: eqObject.length, unit: "км" },
                { name: "Xо", value: eqObject.resistX, unit: "Ом/км" },
                { name: "Rо", value: eqObject.resistR, unit: "Ом/км" }
            ]
            break;
        case ("T") :
            repeater.model = [
                { name: "Мощность S", value: eqObject.powerS, unit: "МВА" },
                { name: "Уровень ВН", value: eqObject.hvLevel, unit: "кВ" },
                { name: "Уровень СН", value: eqObject.mvLevel, unit: "кВ" },
                { name: "Уровень НН", value: eqObject.lvLevel, unit: "кВ" },
                { name: "uKoefH_M", value: eqObject.uKoefH_M, unit: "" },
                { name: "uKoefH_M", value: eqObject.uKoefH_L, unit: "" },
                { name: "uKoefH_M", value: eqObject.uKoefM_L, unit: "" },
                { name: "Регулирование напр.", value: eqObject.regulation, unit: "" }

            ]
        }
    }
}

//        switch (eqObject.index[0]) {
//        case ("S") :
//           secondControlItem = Qt.createQmlObject('',
//            itemDelegate,
//            "systemDelegate");
//        break;

//        case ("W") :
//            secondControlItem = Qt.createQmlObject('',
//               itemDelegate,
//               "wLineDelegate");
//        break;

//        case ("T") :
//            secondControlItem = Qt.createQmlObject('',
//                itemDelegate,
//                "transformerDelegate");
//            break;
//        }
//    }
//    function closing(obj){
//        obj.destroy()
//    }

import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

Page {
    width: 600
    height: 400

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

            Rectangle {
                id: rectangle
                x: 71
                y: 26
                width: 34
                height: 33
                color: "#00000000"
                radius: 44
                border.color: "#ffffff"
            }

            Rectangle {
                id: rectangle1
                x: 343
                y: 26
                width: 34
                height: 33
                color: "#00000000"
                radius: 44
                border.color: "#ffffff"
            }
        }

        Button{
            text: "Рассчитать параметры срабатывания РЗ"
            font.italic: false
            font.bold: false
            font.pointSize: 12
            font.family: "Verdana"
            focusPolicy: Qt.NoFocus
            Layout.fillWidth: false
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            font.capitalization: Font.Capitalize
            clip: false
            onClicked: panel.calculateProtectionParameters()
        }
    }
}

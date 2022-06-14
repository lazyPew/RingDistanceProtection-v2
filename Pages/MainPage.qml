import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.11

Page {
    width: 600
    height: 400

    title: qsTr("Мнемосхема подстанции")

    RowLayout{
        anchors.fill: parent

        Image{
            Layout.fillHeight: true
            Layout.fillWidth: true
            source: "Images/scheme.png"
            fillMode: Image.PreserveAspectFit
        }
    }
    Button{
        onClicked: panel.calculateProtectionParameters()
    }
}

import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11

Rectangle{
    property var terminal

    width: 24
    height: 35
    color: "transparent"
    border.color: "#ffffff"
    border.width: 1

    MouseArea {
        anchors.fill: parent
        onClicked: {
            console.log(terminal.getResults())
        }
    }
}

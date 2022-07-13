import QtQuick 2.9
import QtQuick.Controls 2.4

AbstractButton{
    id: control

    property var terminal

    background: Rectangle{
        id: rectBckg
        radius: 2
        scale: mouseArea.containsPress ? 0.95 : 1
        opacity: mouseArea.containsMouse ? 0.3 : 0.05

    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
        onClicked: {
            protectionPopup.dpObject = terminal
            protectionPopup.open()
        }
    }
}

import QtQuick 2.9
import QtQuick.Controls 2.2
//import Native 1.0

Page {
    width: 600
    height: 400

    title: qsTr("scheme")

    Image{
        source: "Images/scheme.png"
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
    }
}

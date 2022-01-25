import QtQuick 2.4

Item {
    id: item1
    width: 400
    height: 400

    BorderImage {
        id: tagImage
        x: 153
        y: 23
        width: 94
        height: 212
        source: "res/images/radio.png"
    }

    Text {
        id: tagName
        x: 151
        y: 241
        width: 126
        height: 20
        text: qsTr("[ObjectName]")
        elide: Text.ElideNone
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        maximumLineCount: 10000
        renderType: Text.QtRendering
        fontSizeMode: Text.VerticalFit
        font.pointSize: 12
        font.family: "Verdana"
        minimumPointSize: 31
        minimumPixelSize: 19
    }

    Rectangle {
        id: tagActif
        x: 129
        y: 243
        width: 15
        height: 15
        color: "#4ec752"
        radius: 11.5
        layer.smooth: false
        clip: false
    }

    Text {
        id: userName
        x: 129
        y: 262
        width: 143
        height: 22
        text: qsTr("")
        font.pixelSize: 12
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
    states: [
        State {
            name: "Actif"

            PropertyChanges {}

            PropertyChanges {
                target: tagActif
                color: "#d15a5a"
            }

            PropertyChanges {
                target: tagName
                text: qsTr("[ObjectName]")
            }

            PropertyChanges {
                target: userName
                text: qsTr("[UserName]")
            }
        }
    ]
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.5}
}
##^##*/


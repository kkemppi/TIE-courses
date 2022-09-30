import QtQuick 2.0


Item {
    width: 200
    height: 300
    property alias cardValueText: cardValue.text
    property int flipTime: 400

    readonly property string frontState: "FRONT"
    readonly property string backState: "BACK"
    state: backState

    Rectangle {
        id: cardRectangle
        anchors.fill: parent
        border.color: "blue"
        border.width: 10

        Text {
            id: cardValue
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

            color: "black"
            font.pointSize: parent.parent.height / 4
            text: cardModel.cardValue
        }
    }

    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton
        onClicked: {
            if (parent.state === frontState) {
                parent.state = backState
            }
        }
    }

    states: [
        State {
            name: frontState
            PropertyChanges {
                target: cardRectangle
                color: "green"
            }
            PropertyChanges {
                target: cardValue
                visible: true
            }
            PropertyChanges {
                target: rotation
                angle: 0
            }
        },
        State {
            name: backState
            PropertyChanges {
                target: cardRectangle
                color: "red"
            }
            PropertyChanges {
                target: cardValue
                visible: false
            }
            PropertyChanges {
                target: rotation
                angle: 180
            }
        }
    ]

    transform: Rotation {
        id: rotation
        origin.x: cardRectangle.width / 2
        origin.y: cardRectangle.height / 2
        axis.x: 0
        axis.y: 1
        axis.z: 0
    }

    // Using the Flipable type would be an alternative way to implement the flipping animation:
    // https://doc.qt.io/qt-5/qml-qtquick-flipable.html
    transitions: Transition {
        from: "*"
        to: "*"
        SequentialAnimation {
            NumberAnimation {
                target: rotation
                property: "angle"
                duration: flipTime / 2
                to: 90
            }
            PropertyAnimation {
                target: cardValue
                property: "visible"
                duration: 0
            }
            PropertyAnimation {
                target: cardRectangle
                property: "color"
                duration: 0
            }
            NumberAnimation {
                target: rotation
                property: "angle"
                duration: flipTime / 2
                from: 90
            }
        }
    }
}

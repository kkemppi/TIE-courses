import QtQuick 2.0

Item {
    id: container
    width: parent.width / 3; height: parent.height / 1.5;
    property alias cardText: cardValue.text
    anchors.centerIn: parent

    Rectangle {
        id: card
        border.width: 7
        anchors.fill: parent

        Image {
            id: img
            source: "cardfront.jpg"
            anchors.fill: parent
        }

        Text {
            id: cardValue
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            font.pointSize: 12;
            font.bold: true;
        }
    states: [
        State {
            name: "FRONT"
            PropertyChanges {
                target: cardValue
                visible: true
                }
            PropertyChanges {
                target: card
                color: "red"
            }
            PropertyChanges {
                target: img
                source: "cardfront.jpg"
            }
        },
        State {
            name: "BACK"
            PropertyChanges {
                target: cardValue
                visible: false
            }
            PropertyChanges {
                target: card
                color: "green"
            }
            PropertyChanges {
                target: img
                source: "cardback.png"

            }
        }

    ]

    MouseArea {
        anchors.fill: parent
        onClicked: {
            if (card.state === "FRONT")
                card.state = "BACK"
            else
                card.state = "FRONT"
        }
    }

}
}

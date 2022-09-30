import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    id: window
    visible: true
    width: 480
    height: 640
    title: qsTr("Card Game")

    Card {
        id: gameCard
        y: window.height / 15
        anchors.horizontalCenter: parent.horizontalCenter
        width: window.width / 2
        height: window.height / 2
        flipTime: 350
    }

    VerdictRow {
        verdictCard: gameCard

        anchors.top: gameCard.bottom
        anchors.left: gameCard.left
        anchors.right: gameCard.right
        anchors.topMargin: window.height * 0.02
    }

    GuessRow {
        anchors.top: gameCard.bottom
        anchors.left: gameCard.left
        anchors.right: gameCard.right
        anchors.topMargin: window.height * 0.10
    }

    ButtonRow {
        buttonCard: gameCard

        anchors.top: gameCard.bottom
        anchors.left: gameCard.left
        anchors.right: gameCard.right
        anchors.topMargin: window.height * 0.16
    }

    ResultRow {
        anchors.top: gameCard.bottom
        anchors.left: gameCard.left
        anchors.right: gameCard.right
        anchors.topMargin: window.height * 0.25
    }

    ResetButtonRow {
        buttonCard: gameCard

        anchors.top: gameCard.bottom
        anchors.left: gameCard.left
        anchors.right: gameCard.right
        anchors.topMargin: window.height * 0.35
    }
}

import QtQuick 2.9
import QtQuick.Window 2.2
//import cardController 0.2  // needed if the qmlRegisterType is used

Window {
    id: window
    visible: true
    width: 480
    height: 640
    title: qsTr("Card Game")

    Card {
        id: card
        y: window.height / 15
        anchors.horizontalCenter: parent.horizontalCenter
        width: window.width / 2
        height: window.height / 2
        flipTime: 350
    }

    VerdictRow {
        anchors.top: card.bottom
        anchors.left: card.left
        anchors.right: card.right
        anchors.topMargin: window.height * 0.02
    }

    GuessRow {
        anchors.top: card.bottom
        anchors.left: card.left
        anchors.right: card.right
        anchors.topMargin: window.height * 0.10
    }

    ButtonRow {
        anchors.top: card.bottom
        anchors.left: card.left
        anchors.right: card.right
        anchors.topMargin: window.height * 0.16
    }

    ResultRow {
        anchors.top: card.bottom
        anchors.left: card.left
        anchors.right: card.right
        anchors.topMargin: window.height * 0.25
    }

    ResetButtonRow {
        anchors.top: card.bottom
        anchors.left: card.left
        anchors.right: card.right
        anchors.topMargin: window.height * 0.35
    }

    // when using qmlRegisterType, the objects must be created in the QML side
//    CardController {
//        // the same id is used here as in main.cpp (line 15) to get the application working without
//        // other changes when switching how the C++ class is made available to the QML side
//        id: cardController
//    }
}

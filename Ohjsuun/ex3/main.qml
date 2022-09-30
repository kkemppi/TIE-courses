import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.15

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Card Game")

    Card {
        id: card
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    }
    Row {
        id: buttonRow
        anchors.top: card.bottom
        anchors.horizontalCenter: card.horizontalCenter
        spacing: 16
        Button {
            id: smallButton
            text: "Small"
            onClicked: {
                if (card.state === "BACK"){
                    card.state = "FRONT"
                    Logic.currentValue = "1234"
                    card.cardValueText = Logic.currentValue
                    if (Logic.checkSmall() === true){
                        correctGuesses.correct++
                    }else{
                        wrongGuesses.wrong++
                    }
                }

            }
        }
        Button {
            id: bigButton
            text: "Big"
            onClicked: {
                if (card.state === "BACK"){
                    card.state = "FRONT"
                    Logic.currentValue = "1234"
                    card.cardValueText = Logic.currentValue
                    if (Logic.checkBig() === true){
                        correctGuesses.correct++
                    }else{
                        wrongGuesses.wrong++
                    }
                }
            }
        }
    }
    Column {
        spacing: 20
        id: statColumn
        anchors.left: card.right
        anchors.verticalCenter: card.verticalCenter
        padding: 24
        Text {
            id: correctGuesses
            property int correct: 0
            text: "Correct guesses " + correct
        }
        Text {
            id: wrongGuesses
            property int wrong: 0
            text: "Wrong guesses " + wrong
        }
        Text {
            id: resultText
            visible: false
            font.pixelSize: 16
            property string result: "Incorrect"
            text: ""
        }
    }
}

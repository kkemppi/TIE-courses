import QtQuick 2.0

Item {
    id: resultRow

    function gameStatus() {
        return "Correct: " + cardController.correctAnswers + "\n" + "Wrong: " + cardController.incorrectAnswers
    }

    Row {
        Text {
            text: resultRow.gameStatus()
            font.pixelSize: 24
        }
    }
}

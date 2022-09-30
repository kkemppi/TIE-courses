import QtQuick 2.0

Item {
    id: resultRow

    function gameStatus() {
        return "Correct: " + cardModel.correctAnswers + "\n" + "Wrong: " + cardModel.incorrectAnswers;
    }

    Row {
        Text {
            text: resultRow.gameStatus()
            font.pixelSize: 24
        }
    }
}

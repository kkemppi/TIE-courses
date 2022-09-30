import QtQuick 2.0

Item {
    id: resultRow

    function gameStatus() {
        return "Correct: " + cardView.correctAnswers + "\n" +
               "Wrong: " + cardView.incorrectAnswers;
    }

    Row {
        Text {
            text: resultRow.gameStatus()
            font.pixelSize: 24
        }
    }
}

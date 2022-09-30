import QtQuick 2.0

Item {
    property Card verdictCard

    function verdict() {
        if (verdictCard.state === verdictCard.frontState) {
            if (cardView.guessCorrect) {
                return "CORRECT!";
            }
            else {
                return "WRONG!"
            }
        }
        else {
            return "";
        }
    }

    Row {
        Text {
            text: verdict()
            font.pointSize: 30
        }
    }
}

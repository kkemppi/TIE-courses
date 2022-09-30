import QtQuick 2.0


Item {
    function verdict() {
        if (card.state === card.frontState) {
            if (cardController.correct) {
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

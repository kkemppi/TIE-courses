import QtQuick 2.0
import QtQuick.Controls 2.2

Item {
    id: buttonRow

    function buttonOnClickHandler(choice) {
        if (card.state === card.frontState) {
            card.state = card.backState
        }
        cardController.resetPoints();
    }

    Row {
        anchors.right: parent.right

        Button {
            id: resetButton
            text: "Reset"
            font.pointSize: 12
            onClicked: buttonOnClickHandler()
        }
    }
}

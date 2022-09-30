import QtQuick 2.0
import QtQuick.Controls 2.2

Item {
    id: buttonRow
    property Card buttonCard;

    function buttonOnClickHandler(choice) {
        if (buttonCard.state === buttonCard.frontState) {
            buttonCard.state = buttonCard.backState;
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

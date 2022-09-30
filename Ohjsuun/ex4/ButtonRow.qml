import QtQuick 2.0
import QtQuick.Controls 2.2


Item {
    id: buttonRow
    property Card buttonCard

    readonly property string smallChoice: "SMALL"
    readonly property string bigChoice: "BIG"

    function buttonOnClickHandler(choice) {
        if (buttonCard.state === buttonCard.backState) {
            cardController.generateCardValue();
            buttonCard.state = buttonCard.frontState;
            cardController.setCardChoice(choice);
        }
    }

    Row {
        spacing: buttonCard.width - bigButton.width - smallButton.width

        Button {
            id: smallButton
            text: "Small"
            font.pointSize: 20
            onClicked: buttonOnClickHandler(buttonRow.smallChoice)
        }

        Button {
            id: bigButton
            text: "Big"
            font.pointSize: 20
            onClicked: buttonOnClickHandler(buttonRow.bigChoice)
        }
    }
}

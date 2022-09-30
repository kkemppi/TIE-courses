import QtQuick 2.0
import QtQuick.Controls 2.2

Item {
    id: buttonRow

    readonly property string smallChoice: "SMALL"
    readonly property string bigChoice: "BIG"

    function buttonOnClickHandler(choice) {
        if (card.state === card.backState) {
            cardController.generateCardValue();
            card.state = card.frontState;
            cardController.setCardChoice(choice);
        }
    }

    Row {
        spacing: card.width - smallButton.width - bigButton.width

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

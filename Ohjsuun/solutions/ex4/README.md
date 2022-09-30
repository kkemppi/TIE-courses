# MVC Framework

There are three alternative implementations given here: passive MVC, pull MVC and push MVC.

In all alternatives, three C++ classes are used: cardModel, cardController and cardView. The QML code is identical in all alternatives.

The communication between the QML side and the C++ side is limited to:

- functions called from QML side (Q_INVOKABLE) in the cardController class
- property values (Q_PROPERTY) from cardView class used in the QML side

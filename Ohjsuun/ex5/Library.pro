TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cc \
    book.cc \
    cd.cc \
    itemsaver.cpp \
    librarycounter.cc

HEADERS += \
    book.hh \
    cd.hh \
    itemsaver.h \
    librarycounter.hh \
    loanItem.h

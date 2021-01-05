QT += testlib
QT -= gui

TARGET = datetest
CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    ../../WelcomeToTampere/date.cc \
    datetest.cc
SOURCES += \
    ../../WelcomeToTampere/baddate.cc
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../../WelcomeToTampere/date.hh
HEADERS += \
    ../../WelcomeToTampere/baddate.hh

INCLUDEPATH += \
            ../../WelcomeToTampere/

#-------------------------------------------------
#
# Project created by QtCreator 2018-07-27T17:59:20
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++11
#-std=c++11
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += svg
TARGET = try2
TEMPLATE = app


SOURCES += main.cpp\
    NewScore.cpp \
    NoteArea.cpp \
    NewNotes.cpp \
    MsNote.cpp \
    StartWindow.cpp

HEADERS  += \
    NewScore.h \
    NewName.h \
    NewClef.h \
    NewSign.h \
    NewRythm.h \
    NoteArea.h \
    NewNotes.h \
    MsNote.h \
    StartWindow.h

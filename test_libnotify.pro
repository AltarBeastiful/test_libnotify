QT += core
QT -= gui

CONFIG += c++11

TARGET = test_libnotify
CONFIG += console
CONFIG -= app_bundle
CONFIG += link_pkgconfig

TEMPLATE = app

LIBS += -lnotify
PKGCONFIG += glib-2.0 gdk-pixbuf-2.0

SOURCES += main.cpp

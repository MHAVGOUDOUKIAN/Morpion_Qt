TEMPLATE = app
TARGET = main

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_LFLAGS += -no-pie  

SOURCES +=  main.cpp Launcher.cpp
HEADERS += Launcher.hpp
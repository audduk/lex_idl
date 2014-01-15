
TEMPLATE = app
DESTDIR = bin
OBJECTS_DIR = .tmp
MOC_DIR = .tmp
TSM_DIR = .tmp

CONFIG += qt tsm 
#CONFIG += tsmserver
CONFIG += tsmclient

QT -= qui
QT += core xml network

SOURCES += main.cpp 

tsmclient {
    TARGET = testClient

    TSM_CLIENT_SOURCES += test.tsm 
    SOURCES += testClient.cpp
    HEADERS += testClient.h
    DEFINES += TSMCLIENT
}

tsmserver {
    TARGET = testServer

    TSM_SERVER_SOURCES += test.tsm 
    SOURCES += testServer.cpp
    HEADERS += testServer.h
    DEFINES += TSMSERVER
}

INCLUDEPATH += $$(KSADIR)/include 
QMAKE_LIBDIR += $$(KSADIR)/lib 

QMAKE_CLEAN += .tmp/*~

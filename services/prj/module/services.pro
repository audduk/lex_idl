
TEMPLATE = app
INCLUDEPATH += .
OBJECTS_DIR = .obj
DESTDIR = bin
TARGET = josrv

QT -= qui

message($$[QMAKESPEC])

QMAKE_YACC = "C:\Program Files\GnuWin32\bin\yacc.exe"
#QMAKE_YACCFLAGS += -g --report=all
QMAKE_YACCFLAGS += -v

QMAKE_CLEAN += services.output

HEADERS += \
    analizer.h \
    generator.h \
    generator_add.h

SOURCES += \
    analizer.cpp \
    generator.cpp \
    generator_add.cpp \
    main.cpp

LEXSOURCES += services.l

YACCSOURCES += services.y

CONFIG -= release
CONFIG += debug

DEFINES += YY_NO_UNISTD_H

debug {
    TARGET += d
    DEFINES -= YYDEBUG NDEBUG
    DEFINES += TSMDEBUG
}

release {
    DEFINES -= YYDEBUG TSMDEBUG
    DEFINES += NDEBUG
}

target.path = /usr/local/lib/tsm
qmake_c.files = qmake/tsm.prf
qmake_c.path = /usr/lib/qt4/mkspecs/features
#qmake_c.path = $$(QMAKESPEC)/features

INSTALLS += target qmake_c

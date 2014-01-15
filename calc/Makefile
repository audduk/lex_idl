
####### Compiler, tools and options

LEX      = flex
YACC     = yacc
LEXFLAGS = 
YACCFLAGS= -v -d
INCPATH  = -I/usr/lib/qt-3.3.3/mkspecs/default -I. -I. -I$(QTDIR)/include
LINK     = g++
LFLAGS   = 
LIBS     = $(SUBLIBS) -L$(QTDIR)/lib -lqt -lm
DEL_FILE = rm -rf
MOVE     = mv -f

####### Output directory

OBJECTS_DIR = ./

####### Files

HEADERS = 
SOURCES = calc_lex.cpp calc_yacc.cpp
OBJECTS = calc_lex.o calc_yacc.o
DIST	= calc.pro
QMAKE_TARGET = calc
DESTDIR = 
TARGET  = calc

####### Build rules

all:  initScript  Makefile $(TARGET)  postScript 
initScript:
postScript:

$(TARGET):  $(OBJECTS)
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

yaccclean:
	-$(DEL_FILE) calc_yacc.cpp calc_yacc.h calc.output
lexclean:
	-$(DEL_FILE) calc_lex.cpp
clean: yaccclean lexclean
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core

####### Compile

calc_lex.o: calc_lex.cpp 

calc_yacc.o: calc_yacc.cpp calc_yacc.h

calc_yacc.cpp: calc.y
	$(YACC) $(YACCFLAGS) -b calc calc.y
	-$(DEL_FILE) calc_yacc.cpp calc_yacc.h
	-$(MOVE) calc.tab.h calc_yacc.h
	-$(MOVE) calc.tab.c calc_yacc.cpp

calc_yacc.h: calc_yacc.cpp

calc_lex.cpp: calc.l calc_yacc.h
	$(LEX) $(LEXFLAGS) calc.l
	-$(DEL_FILE) calc_lex.cpp 
	-$(MOVE) lex.yy.c calc_lex.cpp

####### Install

install:  

uninstall:  


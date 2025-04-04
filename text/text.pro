QMAKE_CXXFLAGS += -std=c++11

TARGET = test_text

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

OBJECTS_DIR = build/obj

INCLUDEPATH = ../general

SOURCES += \
    main_text.cc \
    text_viewer.cc

HEADERS += \
   ../general/include/contraintes.h \
    ../general/include/dessinable.h \
    ../general/include/support_a_dessin.h \
    ../general/include/constantes.h \
    ../general/include/integrateur.h \
    ../general/include/masse.h \
    ../general/include/ressort.h \
    ../general/include/tissuCompose.h\
    ../general/include/tissuDisque.h\
    ../general/include/tissuRectangle.h\
    ../general/include/tissu.h \
    ../general/include/systeme.h \
    text_viewer.h


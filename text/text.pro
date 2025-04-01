QMAKE_CXXFLAGS += -std=c++11

TARGET = P14_text

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general

SOURCES += \
    main_text.cc \
    text_viewer.cc

HEADERS += \
    ../general/tissu.h \
    ../general/tissuRectangle.h\
    ../general/masse.h \
    ../general/ressort.h \
    ../general/systeme.h \
    ../general/vecteur3D.h \
    ../general/integrateur.h \
    ../general/contraintes.h \
    ../general/constantes.h \
    text_viewer.h \
    ../general/dessinable.h \
    ../general/support_a_dessin.h

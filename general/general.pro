TEMPLATE = lib

CONFIG = staticlib
QMAKE_CXXFLAGS += -std=c++11

SOURCES = masse.cc tissu.cc ressort.cc systeme.cc constantes.cc vecteur3D.cc integrateur.cc tissuRectangle.cc tissuDisque.cc contrainte.cc tissuCompose.cc

HEADERS += \
    masse.h \
    dessinable.h \
    tissu.h \
    ressort.h \
    systeme.h \
    contrainte.h \
    constantes.h \
    vecteur3D.h \
    integrateur.h\
    tissuCompose.h\
    tissuRectangle.h\
    tissuDisque.h \
    support_a_dessin.h

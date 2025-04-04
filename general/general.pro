TEMPLATE = lib

CONFIG = staticlib
QMAKE_CXXFLAGS += -std=c++11

# Dossier pour les fichiers objets
OBJECTS_DIR = build/obj

SOURCES = source/masse.cc source/tissu.cc source/ressort.cc source/systeme.cc source/constantes.cc source/vecteur3D.cc source/integrateur.cc source/tissuRectangle.cc source/tissuDisque.cc source/contrainte.cc source/tissuCompose.cc

HEADERS = include/masse.h \
        include/dessinable.h \
        include/tissu.h \
        include/ressort.h \
        include/systeme.h \
        include/contrainte.h \
        include/constantes.h \
        include/vecteur3D.h \
        include/integrateur.h \
        include/tissuCompose.h \
        include/tissuRectangle.h \
        include/tissuDisque.h \
        include/support_a_dessin.h
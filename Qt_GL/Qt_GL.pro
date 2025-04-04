QT += core gui opengl widgets
QMAKE_CXXFLAGS += -std=c++11

win32:LIBS += -lopengl32


TARGET = P11_gl

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general

SOURCES += \
    main_qt_gl.cc \
    glwidget.cc \
    vue_opengl.cc

OBJECTS_DIR = build/obj

HEADERS += \
    glwidget.h \
    vertex_shader.h \
    vue_opengl.h \
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
    ../general/include/systeme.h 


RESOURCES += \
    resource.qrc

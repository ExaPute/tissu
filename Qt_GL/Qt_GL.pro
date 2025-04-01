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

HEADERS += \
    glwidget.h \
    vertex_shader.h \
    vue_opengl.h \
    ../general/contraintes.h \
    ../general/dessinable.h \
    ../general/support_a_dessin.h \
    ../general/constantes.h \
    ../general/integrateur.h \
    ../general/masse.h \
    ../general/ressort.h \
    ../general/tissuCompose.h\
    ../general/tissuDisque.h\
    ../general/tissuRectangle.h\
    ../general/tissu.h \
    ../general/systeme.h 


RESOURCES += \
    resource.qrc

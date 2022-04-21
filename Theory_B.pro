QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    angulo.cpp \
    basededatos.cpp \
    bomba.cpp \
    button.cpp \
    enemigo.cpp \
    main.cpp \
    mainwindow.cpp \
    objetodinamico.cpp \
    objetoestatico.cpp \
    objetomovcircular.cpp \
    personajeprincipal.cpp \
    reloj.cpp \
    resorte.cpp \
    tiempo.cpp \
    utilidades.cpp \
    vidas.cpp
    ventana.cpp

HEADERS += \
    angulo.h \
    bomba.h \
    button.h \
    enemigo.h \
    mainwindow.h \
    objetodinamico.h \
    objetoestatico.h \
    objetomovcircular.h \
    personajeprincipal.h \
    basededatos.h \
    reloj.h \
    resorte.h \
    tiempo.h \
    utilidades.h \
    vidas.h
    ventana.h

    

FORMS += \
    mainwindow.ui \
    ventana.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagenes.qrc

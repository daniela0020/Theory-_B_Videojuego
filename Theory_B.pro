QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    basededatos.cpp \
<<<<<<< HEAD
    bomba.cpp \
    button.cpp \
    enemigo.cpp \
    enemigoterrestre.cpp \
=======
>>>>>>> 71d70ad141037c54629a8f4e86abf235f1c339bb
    enemigovolador.cpp \
    main.cpp \
    mainwindow.cpp \
    objetodinamico.cpp \
    objetomovcircular.cpp \
    personajeprincipal.cpp \
    reloj.cpp \
    resorte.cpp \
    utilidades.cpp
    ventana.cpp

HEADERS += \
<<<<<<< HEAD
    bomba.h \
    button.h \
    enemigo.h \
    enemigoterrestre.h \
=======
>>>>>>> 71d70ad141037c54629a8f4e86abf235f1c339bb
    enemigovolador.h \
    mainwindow.h \
    objetodinamico.h \
    objetomovcircular.h \
    personajeprincipal.h \
    basededatos.h \
    reloj.h \
    resorte.h \
    utilidades.h
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

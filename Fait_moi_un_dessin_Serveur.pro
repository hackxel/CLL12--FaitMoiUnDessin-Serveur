#-------------------------------------------------
#
# Project created by QtCreator 2012-05-01T16:12:00
#
#-------------------------------------------------

QT       += core gui network

TARGET = Fait_moi_un_dessin_Serveur
TEMPLATE = app


SOURCES += main.cpp\
        dessinserveur.cpp \
    tcpserveur.cpp \
    thclient.cpp

HEADERS  += dessinserveur.h \
    tcpserveur.h \
    thclient.h

FORMS    += dessinserveur.ui

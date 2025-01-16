QT += core gui sql widgets

CONFIG += c++11

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    medecin.cpp \
    medecindialog.cpp \
    medecinmanager.cpp \
    patientdialog.cpp \
    patientmanager.cpp \
    patient.cpp \
    rendezvous.cpp \
    rendezvousdialog.cpp \
    rendezvousmanager.cpp

HEADERS += \
    mainwindow.h \
    medecin.h \
    medecindialog.h \
    medecinmanager.h \
    patientdialog.h \
    patientmanager.h \
    patient.h \
    rendezvous.h \
    rendezvousdialog.h \
    rendezvousmanager.h

FORMS += \
    mainwindow.ui \
    medecindialog.ui \
    patientdialog.ui \
    rendezvousdialog.ui

RESOURCES += resources.qrc

DISTFILES += \
    hopital.db

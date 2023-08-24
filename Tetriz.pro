QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    partie.cpp \
    puits.cpp \
    tetromino.cpp \
    tetromino_i.cpp \
    tetromino_j.cpp \
    tetromino_l.cpp \
    tetromino_o.cpp \
    tetromino_s.cpp \
    tetromino_t.cpp \
    tetromino_z.cpp

HEADERS += \
    mainwindow.h \
    partie.h \
    puits.h \
    tetromino.h \
    tetromino_i.h \
    tetromino_j.h \
    tetromino_l.h \
    tetromino_o.h \
    tetromino_s.h \
    tetromino_t.h \
    tetromino_z.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

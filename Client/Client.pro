QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += network
CONFIG += c++11
CONFIG += console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    alltasks.cpp \
    aureg.cpp \
    connecttoserver.cpp \
    expression.cpp \
    main.cpp \
    reqs.cpp \
    singletask.cpp \
    sta.cpp

HEADERS += \
    alltasks.h \
    aureg.h \
    connecttoserver.h \
    expression.h \
    reqs.h \
    singletask.h \
    sta.h

FORMS += \
    alltasks.ui \
    aureg.ui \
    singletask.ui \
    sta.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QT       += core gui opengl openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/datamodeller.cpp \
    src/datapair.cpp \
    src/handlermodel.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/markermodel.cpp \
    src/queuemodel.cpp \
    src/useragentmodel.cpp \
    src/viewelement.cpp \
    src/taskmodel.cpp

HEADERS += \
    src/datamodeller.h \
    src/datapair.h \
    src/handlermodel.h \
    src/mainwindow.h \
    src/markermodel.h \
    src/queuemodel.h \
    src/useragentmodel.h \
    src/viewelement.h \
    src/taskmodel.h

FORMS += \
    src/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

QT       += core gui opengl openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/about.cpp \
    src/axismanager.cpp \
    src/axismodel.cpp \
    src/customqgraphicsview.cpp \
    src/dataaccessor.cpp \
    src/datafactory.cpp \
    src/datamodel.cpp \
    src/datapair.cpp \
    src/dataprocessor.cpp \
    src/datareader.cpp \
    src/entryhelper.cpp \
    src/generaldata.cpp \
    src/graphicdrawer.cpp \
    src/graphicsmanager.cpp \
    src/handlermodel.cpp \
    src/linemodel.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/markerentry.cpp \
    src/markermodel.cpp \
    src/mousezoomhandler.cpp \
    src/queuemodel.cpp \
    src/searchhelper.cpp \
    src/useragentmodel.cpp \
    src/viewelement.cpp \
    src/taskmodel.cpp

HEADERS += \
    src/about.h \
    src/axismanager.h \
    src/axismodel.h \
    src/customqgraphicsview.h \
    src/dataaccessor.h \
    src/datafactory.h \
    src/datamodel.h \
    src/datapair.h \
    src/dataprocessor.h \
    src/datareader.h \
    src/entryhelper.h \
    src/generaldata.h \
    src/graphicdrawer.h \
    src/graphicsmanager.h \
    src/handlermodel.h \
    src/linemodel.h \
    src/mainwindow.h \
    src/markerentry.h \
    src/markermodel.h \
    src/mousezoomhandler.h \
    src/queuemodel.h \
    src/searchhelper.h \
    src/useragentmodel.h \
    src/viewelement.h \
    src/taskmodel.h

FORMS += \
    src/about.ui \
    src/mainwindow.ui
	
INCLUDEPATH += $$PWD/src

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

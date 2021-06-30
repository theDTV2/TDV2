#ifndef DATAMODELLER_H
#define DATAMODELLER_H
#include <QtGlobal>
#include <QString>
#include <QList>
#include <QSharedPointer>

#include "queuemodel.h"
#include "taskmodel.h"
#include "useragentmodel.h"
#include "handlermodel.h"
#include "markermodel.h"



class DataModeller
{
public:
    static void setDataToProcess(QStringList string);
    static void processRawData();


private:
    static void parseEntry();
    static void getNextLine();

    static void createNewTask();
    static void createNewQueue();
    static void createNewHandler();
    static void createNewUserAgent();
    static void createMarker();

    static void addTaskEnter();
    static void addTaskStop();
    static void addQueueReg();
    static void addQueueSend();
    static void addQueueReceive();
    static void addMarkerOccurance();
    static void addMarkerProperty();
    static void addHandlerEnter();
    static void addHandlerExit();
    static void addUserAgentEnter();
    static void addUserAgentExit();

    static void deleteTask();
    static void deleteQueue();

    inline static QStringList s_rawData = QStringList();
    inline static QString s_currentString;

    inline static QList<TaskModel> s_taskList = QList<TaskModel>();
    inline static QList<QueueModel> s_queueList = QList<QueueModel>();
    inline static QList<MarkerModel> s_markerList = QList<MarkerModel>();
    inline static QList<UserAgentModel> s_userAgentList = QList<UserAgentModel>();
    inline static QList<HandlerModel> s_handlerModel = QList<HandlerModel>();

    //We save the last occured marker, as some operations reference it
    QSharedPointer<MarkerModel> s_lastMarker = QSharedPointer<MarkerModel>(nullptr);




};

#endif // DATAMODELLER_H

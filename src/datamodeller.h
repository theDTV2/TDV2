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


using namespace std;
class DataModeller
{
public:
    static void SetDataToProcess(QStringList string);
    static void ProcessRawData();


private:
    static void ParseEntry();
    static void GetNextLine();

    static void CreateNewTask();
    static void CreateNewQueue();
    static void CreateNewHandler();
    static void CreateNewUserAgent();
    static void CreateMarker();

    static void AddTaskEnter();
    static void AddTaskStop();
    static void AddQueueReg();
    static void AddQueueSend();
    static void AddQueueReceive();
    static void AddMarkerOccurance();
    static void AddMarkerProperty();
    static void AddHandlerEnter();
    static void AddHandlerExit();
    static void AddUserAgentEnter();
    static void AddUserAgentExit();

    static void DeleteTask();
    static void DeleteQueue();

    template<class T>
    static bool GetVariableAtPositionInCurrentEntry(quint8 position, T *read_variable);

    template<class T>
    static bool GetVariableAtPositionInGivenEntry(QString entry,quint8 position, T *read_variable);

    static QString GetStringAtPosition(QString entry,quint8 position);

    inline static QStringList raw_data_ = QStringList();
    inline static QString current_string_;

    inline static QList<TaskModel> task_list_ = QList<TaskModel>();
    inline static QList<QueueModel> queue_list_ = QList<QueueModel>();
    inline static QList<MarkerModel> marker_list_ = QList<MarkerModel>();
    inline static QList<UserAgentModel> userAgent_list_ = QList<UserAgentModel>();
    inline static QList<HandlerModel> handler_list_ = QList<HandlerModel>();

    //We save the last occured marker, as some operations reference it
    QSharedPointer<MarkerModel> last_marker_ = QSharedPointer<MarkerModel>(nullptr);




};

#endif // DATAMODELLER_H

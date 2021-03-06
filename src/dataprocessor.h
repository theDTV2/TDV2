#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H
#include <QtGlobal>
#include <QString>
#include <QList>
#include <QSharedPointer>
#include <QPointer>


#include "queuemodel.h"
#include "taskmodel.h"
#include "useragentmodel.h"
#include "handlermodel.h"
#include "markermodel.h"
#include "searchhelper.h"
#include "entryhelper.h"
#include "generaldata.h"
#include "datafactory.h"


class DataProcessor
{
public:
    static void SetDataToProcess(const QStringList& strings);
    static void ProcessRawData(const QString& file_name);

    /*
     * Return by given type
     */

    static QList<TaskModel> GetTasks();
    static QList<QueueModel> GetQueues();
    static QList<MarkerModel> GetMarkers();
    static QList<UserAgentModel> GetUserAgents();
    static QList<HandlerModel> GetHandlers();
    static void ClearData();

    static quint32 GetAmountOfLinesParsed();

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

    static void LoadSpeed();
    static void LoadMemorySpeed();
    static void LoadTime();

    static void Finalize();

    static quint64 ParseTick(quint64 tick);
    static void DeleteTask();
    static void DeleteQueue();


    template<class T>
    static T GetVariableAtPositionInCurrentEntry(quint8 position) ;



    inline static QStringList raw_data_ = QStringList();
    inline static QString current_string_;

    inline static QList<TaskModel> task_list_ = QList<TaskModel>();
    inline static QList<QueueModel> queue_list_ = QList<QueueModel>();
    inline static QList<MarkerModel> marker_list_ = QList<MarkerModel>();
    inline static QList<UserAgentModel> user_agent_list_ = QList<UserAgentModel>();
    inline static QList<HandlerModel> handler_list_ = QList<HandlerModel>();
    inline static quint64 speed_ = 0;
    inline static quint64 memory_speed_ = 0;
    inline static quint64 time_ = 0;
    inline static QString file_name_;
    inline static quint64 last_tick_read_ = 0;
    inline static bool tick_overflow_ = false;

    //We save the last occured marker, as some operations reference it
    inline static MarkerModel* last_marker_ = nullptr;

    static inline quint32 amount_of_lines_parsed_successfully_;

};

#endif // DATAPROCESSOR_H

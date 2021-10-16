#ifndef DATAFACTORY_H
#define DATAFACTORY_H
#include "datamodel.h"
#include <qmutex.h>


class DataFactory
{
public:
    static QList<TaskModel> GetTasks();
    static QList<QueueModel> GetQueues();
    static QList<MarkerModel> GetMarkers();
    static QList<UserAgentModel> GetUserAgents();
    static QList<HandlerModel> GetHandlers();

    static quint64 GetSpeed();
    static quint64 GetMemorySpeed();
    static quint64 GetTime();
    static QString GetId();

    static quint32 GetAmountOfLines();

    static void AddDataModel(QString id, DataModel* model, bool use_after_load = false);
    static DataModel *GetDataModel();
    static void SetDataModel(const QString& id);
    static bool ContainsDataModel(const QString& id);
    static QStringList GetDataModelStrings();

private:
    static inline QList<DataModel*> data_models_ = QList<DataModel*>();
    static inline DataModel* current_ = nullptr;

    //All data operations must await the mutex to prevent different
    //threads from breaking something
    static inline QMutex mutex_;
};

#endif // DATAFACTORY_H

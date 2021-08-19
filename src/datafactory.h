#ifndef DATAFACTORY_H
#define DATAFACTORY_H
#include "datamodel.h"

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

    static void AddDataModel(QString id, DataModel* model, bool use_after_load = false);
    static DataModel *GetDataModel();
    static void SetDataModel(QString id);
    static bool ContainsDataModel(QString id);
    static QStringList GetDataModelStrings();

private:
    static inline QList<DataModel*> data_models_ = QList<DataModel*>();
    static inline DataModel* current_ = nullptr;
};

#endif // DATAFACTORY_H

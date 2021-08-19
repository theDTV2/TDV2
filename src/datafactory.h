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


    static void AddDataModel(QString id, DataModel model);
    static DataModel *GetDataModel();
    static bool SetDataModel(QString id);
    static QStringList GetDataModelStrings();

private:
    static inline QList<DataModel> data_models_ = QList<DataModel>();
    static inline DataModel* current_ = nullptr;
};

#endif // DATAFACTORY_H

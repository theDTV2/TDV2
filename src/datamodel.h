#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QString>
#include "queuemodel.h"
#include "taskmodel.h"
#include "markermodel.h"
#include "handlermodel.h"
#include "useragentmodel.h"

class DataModel
{
public:
    DataModel(QString id,QList<TaskModel> tasks,  QList<QueueModel> queue, QList<MarkerModel>, QList<UserAgentModel> user_agents, QList<HandlerModel> handlers);

    QList<TaskModel> GetTasks();
    QList<QueueModel> GetQueues();
    QList<MarkerModel> GetMarkers();
    QList<UserAgentModel> GetUserAgents();
    QList<HandlerModel> GetHandlers();

    QString GetId();

private:
    QString id_;
    QList<TaskModel> task_list_ = QList<TaskModel>();
    QList<QueueModel> queue_list_ = QList<QueueModel>();
    QList<MarkerModel> marker_list_ = QList<MarkerModel>();
    QList<UserAgentModel> user_agent_list_ = QList<UserAgentModel>();
    QList<HandlerModel> handler_list_ = QList<HandlerModel>();

};

#endif // DATAMODEL_H

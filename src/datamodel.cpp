#include "datamodel.h"


DataModel::DataModel(QString id, QList<TaskModel> tasks, QList<QueueModel> queues, QList<MarkerModel>, QList<UserAgentModel> user_agents, QList<HandlerModel> handlers)
    :id_(id),task_list_(tasks),queue_list_(queues),user_agent_list_(user_agents),handler_list_(handlers)
{

}

QList<TaskModel> DataModel::GetTasks()
{
    return task_list_;
}

QList<QueueModel> DataModel::GetQueues()
{
    return queue_list_;
}

QList<MarkerModel> DataModel::GetMarkers()
{
    return marker_list_;
}

QList<UserAgentModel> DataModel::GetUserAgents()
{
    return user_agent_list_;
}

QList<HandlerModel> DataModel::GetHandlers()
{
    return handler_list_;
}

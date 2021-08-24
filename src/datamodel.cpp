#include "datamodel.h"


DataModel::DataModel(const QString& id, const QList<TaskModel> &tasks, const QList<QueueModel> &queues, const QList<MarkerModel> &markers, const QList<UserAgentModel> &user_agents, const QList<HandlerModel> &handlers, quint64 speed, quint64 memory_speed, quint64 time)
    :id_(id),task_list_(tasks),
      queue_list_(queues),
      marker_list_(markers),
      user_agent_list_(user_agents),
      handler_list_(handlers),
      speed_(speed),
      memory_speed_(memory_speed),
      time_(time)
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

QString DataModel::GetId()
{
    return id_;
}

void DataModel::SetId(const QString &id)
{
    id_ = id;
}

quint64 DataModel::GetSpeed()
{
    return speed_;
}

quint64 DataModel::GetMemorySpeed()
{
    return memory_speed_;
}

quint64 DataModel::GetTime()
{
    return time_;
}

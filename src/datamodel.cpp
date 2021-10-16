#include "datamodel.h"


DataModel::DataModel(const QString& id,
                     const QList<TaskModel> &tasks,
                     const QList<QueueModel> &queues,
                     const QList<MarkerModel> &markers,
                     const QList<UserAgentModel> &user_agents,
                     const QList<HandlerModel> &handlers,
                     quint64 speed, quint64 memory_speed,
                     quint64 time,
                     quint32 amount_of_lines)
    :id_(id),task_list_(tasks),
      queue_list_(queues),
      marker_list_(markers),
      user_agent_list_(user_agents),
      handler_list_(handlers),
      speed_(speed),
      memory_speed_(memory_speed),
      time_(time),
      amount_of_data(amount_of_lines)
{

}

/**
 * @brief getter
 * @return task list
 */
QList<TaskModel> DataModel::GetTasks()
{
    return task_list_;
}

/**
 * @brief getter
 * @return queue list
 */
QList<QueueModel> DataModel::GetQueues()
{
    return queue_list_;
}

/**
 * @brief getter
 * @return marker list
 */
QList<MarkerModel> DataModel::GetMarkers()
{
    return marker_list_;
}

/**
 * @brief getter
 * @return user agent list
 */
QList<UserAgentModel> DataModel::GetUserAgents()
{
    return user_agent_list_;
}

/**
 * @brief getter
 * @return handler list
 */
QList<HandlerModel> DataModel::GetHandlers()
{
    return handler_list_;
}

/**
 * @brief getter
 * @return id
 */
QString DataModel::GetId()
{
    return id_;
}

/**
 * @brief setter
 * @param id id to set
 */
void DataModel::SetId(const QString &id)
{
    id_ = id;
}

/**
 * @brief getter
 * @param speed
 */
quint64 DataModel::GetSpeed()
{
    return speed_;
}

/**
 * @brief getter
 * @param memory speed
 */
quint64 DataModel::GetMemorySpeed()
{
    return memory_speed_;
}

/**
 * @brief getter
 * @param time
 */
quint64 DataModel::GetTime()
{
    return time_;
}

quint32 DataModel::GetAmountOfLines()
{
    return amount_of_data;
}

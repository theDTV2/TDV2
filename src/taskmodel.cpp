#include "taskmodel.h"

/**
 * @brief Constructor
 * @param name name to use
 */
TaskModel::TaskModel(const QString& name)
    : ViewElement(name)
{
}
/**
 * @brief Constructor
 * @param name name to use
 * @param task_id task id to use
 * @param creation_time time task was created on
 */
TaskModel::TaskModel(const QString& name, quint16 task_id, quint64 creation_time)
    : ViewElement(name, task_id, creation_time)
{
}

/**
 * @brief setter
 * @param new_priority priority to ste
 */
void TaskModel::SetPriority(const QString& new_priority)
{
    priority_ = new_priority;
}

/**
 * @brief getter
 * @param new_priority priority to ste
 */
QString TaskModel::GetPrority() const
{
    return priority_;
}

/**
 * @brief Add start
 * @param start_time start time to set
 */
void TaskModel::AddStart(quint64 time)
{
    start_time_ = time;
}

/**
 * @brief Add stop
 * @param stopTime
 */
void TaskModel::AddStop(quint64 stop_time)
{
    if (start_time_ == 0)
        return;

    AddToList(start_time_,stop_time);
    start_time_ = 0;
}

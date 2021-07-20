#include "taskmodel.h"

TaskModel::TaskModel(QString name)
    : ViewElement(name)
{
}

void TaskModel::SetPriority(QString new_priority)
{
    priority_ = new_priority;
}
QString TaskModel::GetPrority()
{
    return priority_;
}

void TaskModel::AddStart(quint64 start_time)
{
    start_time_ = start_time;
}
void TaskModel::AddStop(quint64 stopTime)
{
    if (start_time_ == 0)
        return;

    AddToList(start_time_,stopTime);
    start_time_ = 0;
}

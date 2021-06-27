#include "taskmodel.h"

TaskModel::TaskModel(QString name)
    : ViewElement(name)
{
}

void TaskModel::setPriority(QString newPriority)
{
    m_priority = newPriority;
}
QString TaskModel::getPrority()
{
    return m_priority;
}

void TaskModel::addStart(quint64 startTime)
{
    m_startTime = startTime;
}
void TaskModel::addStop(quint64 stopTime)
{
    if (m_startTime == 0)
        return;

    addToList(m_startTime,stopTime);
    m_startTime = 0;
}

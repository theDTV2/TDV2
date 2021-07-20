#include "queuemodel.h"

QueueModel::QueueModel(QString name)
    : ViewElement(name)
{

}

void QueueModel::AddQueueHeight(quint64 newTime)
{
    if (last_time_ == 0)
    {
        last_time_ = newTime;
        current_height_++;
        return;
    }

    SetQueueHeight(last_time_, newTime, current_height_);
    current_height_++;
    last_time_ = newTime;

}
void QueueModel::RemoveQueueHeight(quint64 newTime)
{
    SetQueueHeight(last_time_, newTime, current_height_);
    current_height_--;
    last_time_ = newTime;

}

void QueueModel::SetQueueHeight(quint64 startTime, quint64 endTime, quint16 height)
{
    AddToList(startTime,endTime,height);
}

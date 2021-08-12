#include "queuemodel.h"

QueueModel::QueueModel(quint16 id, quint64 creation_time)
    : ViewElement(id,creation_time)
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

quint16 QueueModel::GetMaxHeight()
{
    quint16 height = 0;

    for (auto e : *GetList())
    {
        if (e.GetHeight() > height)
            height = e.GetHeight();
    }
    return height;
}

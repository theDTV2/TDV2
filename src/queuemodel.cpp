#include "queuemodel.h"

/**
 * @brief Construct QueueModel using given values
 * @param id
 * @param creation_time
 */
QueueModel::QueueModel(quint16 id, quint64 creation_time)
    : ViewElement(id,creation_time)
{

}

/**
 * @brief Creates a new viewelement with new height to visualize steps
 * @param newTime
 */
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

/**
 * @brief Creates a new viewelement with new height to visualize steps. Similar to AddQueueHeight(), but lowers instead of increases
 * @param newTime.
 */
void QueueModel::RemoveQueueHeight(quint64 newTime)
{
    SetQueueHeight(last_time_, newTime, current_height_);
    current_height_--;
    last_time_ = newTime;

}

/**
 * @brief Set queue height in a specific region to value
 * @param start_time start time to use
 * @param end_time end time to use
 * @param height height to use
 */
void QueueModel::SetQueueHeight(quint64 start_time, quint64 end_time, quint16 height)
{
    AddToList(start_time,end_time,height);
}

/**
 * @brief returns max height of all height values in queuemodel
 * @return max height
 */
quint16 QueueModel::GetMaxHeight()
{
    quint16 height = 0;

    height =  std::max_element(GetList()->begin(),
                               GetList()->end(),
                               [](const DataPair& a,const DataPair& b){return (a.GetHeight() < b.GetHeight());})->GetHeight();

    return height;
}

#include "datapair.h"

DataPair::DataPair(quint64 startTime, quint64 endTime, quint16 height):
    start_time_(startTime),end_time_(endTime),height_(height)
{
lenght_ = endTime - startTime;

}


void DataPair::SetStartTime(quint64 start_time)
{
    start_time_ = start_time;
}

void DataPair::SetEndTime(quint64 endTime)
{
    end_time_ = endTime;
}

void DataPair::SetHeight(quint16 newHeight)
{
    height_ = newHeight;
}


quint64 DataPair::GetStartTime() const
{
    return start_time_;
}

quint64 DataPair::GetEndTime() const
{
    return end_time_;
}


quint64 DataPair::GetLenght() const
{
    return lenght_;
}

void DataPair::AddHeight()
{
    lenght_++;
}

void DataPair::LowerHeight()
{
    if (height_ > 0)
      --lenght_;
}



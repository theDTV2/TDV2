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

void DataPair::SetEndTime(quint64 end_time)
{
    end_time_ = end_time;
    lenght_ = end_time - start_time_;
}

void DataPair::SetHeight(quint16 new_height)
{
    height_ = new_height;
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

quint16 DataPair::GetHeight() const
{

    return height_;
}

void DataPair::AddHeight()
{
    height_++;
}

void DataPair::LowerHeight()
{
    if (height_ > 0)
      --height_;
}



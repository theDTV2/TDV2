#include "generaldata.h"

void GeneralData::SetSpeed(quint64 value)
{
    speed_ = value;
}

quint64 GeneralData::GetSpeed()
{
    return speed_;
}

void GeneralData::SetMemorySpeed(quint64 value)
{
    memory_speed_ = value;
}

quint64 GeneralData::GetMemorySpeed()
{
    return memory_speed_;
}

void GeneralData::SetTime(quint64 value)
{
    time_ = value;
}

quint64 GeneralData::GetTime()
{
    return time_;
}


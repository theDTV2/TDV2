#include "datapair.h"

DataPair::DataPair(quint64 startTime, quint64 endTime, quint16 height):
    m_startTime(startTime),m_endTime(endTime),m_height(height)
{
m_lenght = endTime - startTime;

}


void DataPair::setStartTime(quint64 startTime)
{
    m_startTime = startTime;
}

void DataPair::setEndTime(quint64 endTime)
{
    m_endTime = endTime;
}

void DataPair::setHeight(quint16 newHeight)
{
    m_height = newHeight;
}


quint64 DataPair::getStartTime()
{
    return m_startTime;
}

quint64 DataPair::getEndTime()
{
    return m_endTime;
}


quint64 DataPair::getLenght()
{
    return m_lenght;
}

void DataPair::addHeight()
{
    m_lenght++;
}

void DataPair::lowerHeight()
{
    if (m_height > 0)
      m_lenght--;
}



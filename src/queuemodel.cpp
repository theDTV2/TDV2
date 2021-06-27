#include "queuemodel.h"

QueueModel::QueueModel(QString name)
    : ViewElement(name)
{

}

void QueueModel::addQueueHeight(quint64 newTime)
{
    if (m_lastTime == 0)
    {
        m_lastTime = newTime;
        m_currentheight++;
        return;
    }

    setQueueHeight(m_lastTime, newTime, m_currentheight);
    m_currentheight++;
    m_lastTime = newTime;

}
void QueueModel::remoteQueueHeight(quint64 newTime)
{
    setQueueHeight(m_lastTime, newTime, m_currentheight);
    m_currentheight--;
    m_lastTime = newTime;

}

void QueueModel::setQueueHeight(quint64 startTime, quint64 endTime, quint16 height)
{
    addToList(startTime,endTime,height);
}

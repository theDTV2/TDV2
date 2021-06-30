#include "viewelement.h"

ViewElement::ViewElement(QString name)
{
    m_name = name;
}


void ViewElement::setName (QString newName)
{
    m_name = newName;
}
QString ViewElement::getName()
{
    return m_name;
}

void ViewElement::clearList()
{
    m_entries.clear();
}

void ViewElement::addToList(quint64 startTime, quint64 endTime)
{
    DataPair newEntry = DataPair(startTime, endTime);

    m_entries.append(newEntry);
}
void ViewElement::addToList(quint64 startTime, quint64 endTime, quint16 height)
{
    DataPair newEntry = DataPair(startTime, endTime, height);

    m_entries.append(newEntry);
}

QList<DataPair>* ViewElement::getList()
{
    return &m_entries;
}

void ViewElement::setCreationTime(quint64 creationTime)
{
    m_creationTime = creationTime;
}
quint64 ViewElement::getCreationTime()
{
    return m_creationTime;
}

void ViewElement::setTaskId(quint64 taskId)
{
    m_taskId = taskId;
}
quint16 ViewElement::getTaskId()
{
    return m_taskId;
}


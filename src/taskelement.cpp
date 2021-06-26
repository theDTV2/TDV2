#include "taskelement.h"

TaskElement::TaskElement(QString name)
{
    m_name = name;
}


void TaskElement::setName (QString newName)
{
    m_name = newName;
}
QString TaskElement::getName()
{
    return m_name;
}

void TaskElement::clearList()
{
    m_entries.clear();
}

void TaskElement::addToList(quint64 startTime, quint64 endTime)
{
    DataPair newEntry = DataPair(startTime, endTime);

    m_entries.append(newEntry);
}
void TaskElement::addToList(quint64 startTime, quint64 endTime, quint16 height)
{
    DataPair newEntry = DataPair(startTime, endTime, height);

    m_entries.append(newEntry);
}

QList<DataPair>* TaskElement::getList()
{
    return &m_entries;
}

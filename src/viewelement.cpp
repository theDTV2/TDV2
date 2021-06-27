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

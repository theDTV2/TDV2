#include "viewelement.h"

ViewElement::ViewElement(QString name)
{
    name_ = name;
}


void ViewElement::SetName (QString new_name)
{
    name_ = new_name;
}
QString ViewElement::GetName()
{
    return name_;
}

void ViewElement::ClearList()
{
    entries_.clear();
}

void ViewElement::AddToList(quint64 start_time, quint64 end_time)
{
    DataPair newEntry = DataPair(start_time, end_time);

    entries_.append(newEntry);
}
void ViewElement::AddToList(quint64 start_time, quint64 endTime, quint16 height)
{
    DataPair newEntry = DataPair(start_time, endTime, height);

    entries_.append(newEntry);
}

QList<DataPair>* ViewElement::GetList()
{
    return &entries_;
}

void ViewElement::SetCreationTime(quint64 creationTime)
{
    creation_time_ = creationTime;
}
quint64 ViewElement::GetCreationTime()
{
    return creation_time_;
}

void ViewElement::SetTaskId(quint64 task_id)
{
    task_id_ = task_id;
}
quint16 ViewElement::GetTaskId()
{
    return task_id_;
}


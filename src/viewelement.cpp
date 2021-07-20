#include "viewelement.h"

ViewElement::ViewElement(QString name):
    name_(name)
{
}

ViewElement::ViewElement(QString name, quint16 task_id, quint64 creation_time):
    name_(name), task_id_(task_id),creation_time_(creation_time)
{
}

ViewElement::ViewElement(quint16 task_id, quint64 creation_time):
    task_id_(task_id),creation_time_(creation_time)
{
}

ViewElement::ViewElement(QString name, quint16 task_id):
    name_(name), task_id_(task_id)
{
}


void ViewElement::SetName (QString new_name)
{
    name_ = new_name;
}


const QString ViewElement::GetName()
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
void ViewElement::AddToList(quint64 start_time, quint64 end_time, quint16 height)
{
    DataPair new_entry = DataPair(start_time, end_time, height);

    entries_.append(new_entry);
}

QList<DataPair>* ViewElement::GetList()
{
    return &entries_;
}

void ViewElement::SetCreationTime(quint64 creationTime)
{
    creation_time_ = creationTime;
}
quint64 ViewElement::GetCreationTime() const
{
    return creation_time_;
}

void ViewElement::SetTaskId(quint64 task_id)
{
    task_id_ = task_id;
}
quint16 ViewElement::GetTaskId() const
{
    return task_id_;
}


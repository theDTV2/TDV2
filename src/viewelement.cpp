#include "viewelement.h"

ViewElement::ViewElement(const QString& name):
    name_(name), task_id_(0),creation_time_(0)
{
}

ViewElement::ViewElement(const QString& name, quint16 task_id, quint64 creation_time):
    name_(name), task_id_(task_id),creation_time_(creation_time)
{
}

ViewElement::ViewElement(quint16 task_id, quint64 creation_time):
    task_id_(task_id),creation_time_(creation_time)
{
}

ViewElement::ViewElement(const QString& name, quint16 task_id):
    name_(name),task_id_(task_id),creation_time_(0)
{
}


void ViewElement::SetName(const QString& new_name)
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

void ViewElement::SetElementId(quint64 task_id)
{
    task_id_ = task_id;
}
quint16 ViewElement::GetElementId() const
{
    return task_id_;
}

quint64 ViewElement::GetLargestEndTime()
{
    /*Theoretically we could just take the end time of the last element, but it is
     * not guaranteed by design, that that this is the largest element
    */

    quint64 max = 0;

    max =  std::max_element(entries_.begin(),
                            entries_.end(),
                            [](const DataPair& a,const DataPair& b){return (a.GetEndTime() < b.GetEndTime());})->GetEndTime();

    return max;
}


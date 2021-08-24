#include "viewelement.h"

/**
 * @brief Constructor
 * @param name name to set
 */
ViewElement::ViewElement(const QString& name):
    name_(name), task_id_(0),creation_time_(0)
{
}

/**
 * @brief Constructor
 * @param name name to set
 * @param task_id task id to set
 * @param creation_time creation time to set
 */
ViewElement::ViewElement(const QString& name, quint16 task_id, quint64 creation_time):
    name_(name), task_id_(task_id),creation_time_(creation_time)
{
}

/**
 * @brief Constructor
 * @param task_id task id to set
 * @param creation_time creation time to set
 */
ViewElement::ViewElement(quint16 task_id, quint64 creation_time):
    task_id_(task_id),creation_time_(creation_time)
{
}

/**
 * @brief Constructor
 * @param name name to set
 * @param task_id task id to set
 */
ViewElement::ViewElement(const QString& name, quint16 task_id):
    name_(name),task_id_(task_id),creation_time_(0)
{
}

/**
 * @brief setter
 * @param new_name new name to set
 */
void ViewElement::SetName(const QString& new_name)
{
    name_ = new_name;
}

/**
 * @brief getter
 * @return name
 */
const QString ViewElement::GetName()
{
    return name_;
}

/**
 * @brief clear list of entries
 */
void ViewElement::ClearList()
{
    entries_.clear();
}

/**
 * @brief Add entry to datapair list
 * @param start_time time to start in
 * @param end_time time to start in
 */
void ViewElement::AddToList(quint64 start_time, quint64 end_time)
{
    DataPair newEntry = DataPair(start_time, end_time);

    entries_.append(newEntry);
}
/**
 * @brief Add entry to datapair list using an extra height parameter
 * @param start_time time to start in
 * @param end_time time to start in
 * @param height height ot use
 */
void ViewElement::AddToList(quint64 start_time, quint64 end_time, quint16 height)
{
    DataPair new_entry = DataPair(start_time, end_time, height);

    entries_.append(new_entry);
}

/**
 * @brief getter
 * @return list
 */
QList<DataPair>* ViewElement::GetList()
{
    return &entries_;
}

/**
 * @brief setter
 * @param creation_time time to set
 */
void ViewElement::SetCreationTime(quint64 creation_time)
{
    creation_time_ = creation_time;
}

/**
 * @brief getter
 * @return  get creation time
 */
quint64 ViewElement::GetCreationTime() const
{
    return creation_time_;
}

/**
 * @brief setter
 * @param task_id id to set
 */
void ViewElement::SetElementId(quint64 task_id)
{
    task_id_ = task_id;
}

/**
 * @brief getter
 * @return id
 */
quint16 ViewElement::GetElementId() const
{
    return task_id_;
}

/**
 * @brief search for largest end time
 * @return largest end time
 */
quint64 ViewElement::GetLargestEndTime()
{
    /*Theoretically we could just take the end time of the last element, but it is
     * not guaranteed by design, that that this is the largest element
    */

    if (entries_.isEmpty())
            return 0;


    quint64 max = 0;

    max =  std::max_element(entries_.begin(),
                            entries_.end(),
                            [](const DataPair& a,const DataPair& b){return (a.GetEndTime() < b.GetEndTime());})->GetEndTime();
    return max;
}


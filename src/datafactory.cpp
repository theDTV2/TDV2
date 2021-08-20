#include "datafactory.h"


QList<TaskModel> DataFactory::GetTasks()
{
    return current_->GetTasks();
}

QList<QueueModel> DataFactory::GetQueues()
{
    return current_->GetQueues();
}

QList<MarkerModel> DataFactory::GetMarkers()
{
    return current_->GetMarkers();
}

QList<UserAgentModel> DataFactory::GetUserAgents()
{
    return current_->GetUserAgents();
}

QList<HandlerModel> DataFactory::GetHandlers()
{
    return current_->GetHandlers();
}

quint64 DataFactory::GetSpeed()
{
    mutex_.lock();
    quint64 var = current_->GetSpeed();
    mutex_.unlock();
    return var;
}

quint64 DataFactory::GetMemorySpeed()
{
    mutex_.lock();
    quint64 var = current_->GetMemorySpeed();
    mutex_.unlock();
    return var;
}

quint64 DataFactory::GetTime()
{
    mutex_.lock();
    quint64 var = current_->GetTime();
    mutex_.unlock();
    return var;
}

QString DataFactory::GetId()
{
    return current_->GetId();
}

void DataFactory::AddDataModel(QString id, DataModel* model, bool use_after_load)
{
    //If an model with the same id is already in the list,
    //we adjust the name of the new element until we dont find one
    if (!ContainsDataModel(id))
    {
        data_models_.append(model);

        if (use_after_load)
            SetDataModel(id);
        return;
    }

    int i = 1;
    QString new_id = id;
    while (ContainsDataModel(new_id))
    {
        new_id = id.append(" " + QString::number(i));
    }
    model->SetId(new_id);
    data_models_.append(model);
    if (use_after_load)
        SetDataModel(id);

}

void DataFactory::SetDataModel(QString id)
{
    mutex_.lock();
    for (auto e : data_models_)
    {
        if (e->GetId() == id)
        {
            current_ = e;
        }
    }
    mutex_.unlock();

}

bool DataFactory::ContainsDataModel(QString id)
{
    mutex_.lock();
    for (auto e : data_models_)
    {
        if (e->GetId() == id)
        {
            mutex_.unlock();
            return true;
        }
    }

    mutex_.unlock();
    return false;
}

QStringList DataFactory::GetDataModelStrings()
{
    mutex_.lock();
    QStringList list;
    for (auto e : data_models_)
        list.append(e->GetId());

    mutex_.unlock();
    return list;
}

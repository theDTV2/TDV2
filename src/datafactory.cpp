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
    return current_->GetSpeed();
}

quint64 DataFactory::GetMemorySpeed()
{
    return current_->GetMemorySpeed();
}

quint64 DataFactory::GetTime()
{
    return current_->GetTime();
}

QString DataFactory::GetId()
{
    return current_->GetId();
}

void DataFactory::AddDataModel(QString id, DataModel* model, bool use_after_load)
{
    //If an model with the same id is already in the list,
    //we adjust the name of the new element until we dont find one
    if (!SetDataModel(id))
    {
        data_models_.append(model);
        qDebug("%i",data_models_.count());

        if (use_after_load)
            SetDataModel(id);
        return;
    }

    int i = 1;
    QString new_id = id;;
    while (!SetDataModel(new_id))
    {
        new_id = id.append(" " + QString::number(i));

    }
    model->SetId(new_id);
    data_models_.append(model);
    if (use_after_load)
        SetDataModel(id);

}

bool DataFactory::SetDataModel(QString id)
{
    for (auto e : data_models_)
    {
        if (e->GetId() == id)
        {

            current_ = e;
            return true;

        }
    }
    return false;
}

QStringList DataFactory::GetDataModelStrings()
{
    QStringList list;
    for (auto e : data_models_)
        list.append(e->GetId());
    return list;
}

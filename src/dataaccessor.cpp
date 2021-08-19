#include "dataaccessor.h"


QList<TaskModel> DataAccessor::GetTasks()
{
    return DataFactory::GetTasks();
}

QList<QueueModel> DataAccessor::GetQueues()
{
    return DataFactory::GetQueues();
}

QList<MarkerModel> DataAccessor::GetMarkers()
{
    return DataFactory::GetMarkers();
}

QList<UserAgentModel> DataAccessor::GetUserAgents()
{
    return DataFactory::GetUserAgents();
}

QList<HandlerModel> DataAccessor::GetHandlers()
{
    return DataFactory::GetHandlers();
}

quint64 DataAccessor::GetSpeed()
{
    return DataFactory::GetSpeed();
}

quint64 DataAccessor::GetMemorySpeed()
{
    return DataFactory::GetMemorySpeed();
}

quint64 DataAccessor::GetTime()
{
    return DataFactory::GetTime();
}

QString DataAccessor::GetId()
{
    return DataFactory::GetId();
}

qreal DataAccessor::GetXAxisLenght()
{

    return GetMaxInList(GetTasks(),GetQueues(),GetUserAgents(),GetHandlers());

}

qreal DataAccessor::GetYAxisLenght()
{
    qreal value = 0;

    value += 100;
    value += GetTasks().count() * 125;

    value += 100;
    value += GetQueues().count() * 125;

    value += 100;
    value += GetUserAgents().count() * 125;

    value += 100;
    value += GetHandlers().count() * 125;

    return value;
}


void DataAccessor::SelectDataModel(QString id)
{
    return DataFactory::SetDataModel(id);
}



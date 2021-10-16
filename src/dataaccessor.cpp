#include "dataaccessor.h"


/**
 * @brief Gets Task-list from currently selected DataModel. See DataFactory::SetDataModel
 * @return Task-List
 */
QList<TaskModel> DataAccessor::GetTasks()
{
    return DataFactory::GetTasks();
}

/**
 * @brief Gets Queue-list from currently selected DataModel. See DataFactory::SetDataModel
 * @return Queue-List
 */
QList<QueueModel> DataAccessor::GetQueues()
{
    return DataFactory::GetQueues();
}

/**
 * @brief Gets Marker-list from currently selected DataModel. See DataFactory::SetDataModel
 * @return Marker-List
 */
QList<MarkerModel> DataAccessor::GetMarkers()
{
    return DataFactory::GetMarkers();
}

/**
 * @brief Gets User-Agent-list from currently selected DataModel. See DataFactory::SetDataModel
 * @return User-Agent-List
 */
QList<UserAgentModel> DataAccessor::GetUserAgents()
{
    return DataFactory::GetUserAgents();
}

/**
 * @brief Gets Handler-list from currently selected DataModel. See DataFactory::SetDataModel
 * @return Handler-List
 */
QList<HandlerModel> DataAccessor::GetHandlers()
{
    return DataFactory::GetHandlers();
}

/**
 * @brief Gets speed from currently selected DataModel. See DataFactory::SetDataModel
 * @return speed
 */
quint64 DataAccessor::GetSpeed()
{
    return DataFactory::GetSpeed();
}

/**
 * @brief Gets memory speed from currently selected DataModel. See DataFactory::SetDataModel
 * @return memory speed
 */
quint64 DataAccessor::GetMemorySpeed()
{
    return DataFactory::GetMemorySpeed();
}

/**
 * @brief Gets time from currently selected DataModel. See DataFactory::SetDataModel
 * @return time
 */
quint64 DataAccessor::GetTime()
{
    return DataFactory::GetTime();
}

/**
 * @brief Gets id from currently selected DataModel. See DataFactory::SetDataModel
 * @return id
 */
QString DataAccessor::GetId()
{
    return DataFactory::GetId();
}


/**
 * @brief Calculates X Axis Lenghtfrom currently selected DataModel. See DataFactory::SetDataModel
 * @return X lenght
 */
qreal DataAccessor::GetXAxisLenght()
{

    return GetMaxInList(GetTasks(),GetQueues(),GetUserAgents(),GetHandlers());

}

/*
 *@brief  calculates the YAxisLenght using the saved data
 *@return Y axis lenghtt
 * */
qreal DataAccessor::GetYAxisLenght()
{
    qreal value = 0;

    value += LINE_HEIGHT;
    value += GetTasks().count() * LINE_HEIGHT + LINE_SPACER;

    value += LINE_HEIGHT;
    value += GetQueues().count() * LINE_HEIGHT + LINE_SPACER;

    value += LINE_HEIGHT;
    value += GetUserAgents().count() * LINE_HEIGHT + LINE_SPACER;

    value += LINE_HEIGHT;
    value += GetHandlers().count() * LINE_HEIGHT + LINE_SPACER;

    return value;
}

/*
 * @brief Searches the DataModel List for a model with the same name, and selects it.
 * This causes all getters above to use said model when accessing data
 * It is assumed, that an getter with the given id exists
 * @param id id to use
 * */
void DataAccessor::SelectDataModel(QString id)
{
    return DataFactory::SetDataModel(id);
}



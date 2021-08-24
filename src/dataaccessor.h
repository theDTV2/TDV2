#ifndef DATAACCESSOR_H
#define DATAACCESSOR_H
#include "datafactory.h"

#define LINE_HEIGHT 50
#define LINE_SPACER 5

class DataAccessor
{

public:
static QList<TaskModel> GetTasks();

static QList<QueueModel> GetQueues();

static QList<MarkerModel> GetMarkers();

static QList<UserAgentModel> GetUserAgents();

static QList<HandlerModel> GetHandlers();

static quint64 GetSpeed();

static quint64 GetMemorySpeed();

static quint64 GetTime();

static QString GetId();

static qreal GetXAxisLenght();

static qreal GetYAxisLenght();

static void SelectDataModel(QString id);


private:


template<typename T, typename ... rest>
static qreal GetMaxInList(QList<T> list_to_search, rest... lists)
{
    //Iterate over each element
    quint64 max_time = 0;

    for (auto &e : list_to_search)
    {

       max_time = qMax(e.GetLargestEndTime(),max_time);
    }

    //Is our value larger/smaller than the next one in the parameter pack?
    quint64 new_max = (GetMaxInList(lists...));
    if (max_time > new_max)
        return max_time;
    return new_max;
}


template<typename T>
static qreal GetMaxInList(QList<T> list_to_search)
{
    //Base case
    quint64 max_time = 0;

    for (auto &e : list_to_search)
    {
      max_time = qMax(e.GetLargestEndTime(),max_time);
    }
    return max_time;
}

};

#endif // DATAACCESSOR_H

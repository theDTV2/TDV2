#include "searchhelper.h"

template<class T>
T SearchHelper::FindInList(QList<T> list_to_search, quint64 id)
{
    auto it = find_if(list_to_search.begin(),list_to_search.end(), [&id](const ViewElement& element) {
        return element.GetTaskId() == id;
    });

    if (list_to_search.end() != it)
        return *it;

   //TODO: Implement proper Exception Class
   throw "ERROR";
}


template<>
MarkerModel SearchHelper::FindInList(QList<MarkerModel> list_to_search, quint64 id)
{
    auto it = find_if(list_to_search.begin(),list_to_search.end(), [id](const MarkerModel& element) {
        return element.GetNumber() == id;
    });

    if (list_to_search.end() != it)
        return *it;

   //TODO: Implement proper Exception Class
   throw "ERROR";
}


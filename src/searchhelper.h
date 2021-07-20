#ifndef SEARCHHELPER_H
#define SEARCHHELPER_H

#include "queuemodel.h"
#include "taskmodel.h"
#include "useragentmodel.h"
#include "handlermodel.h"
#include "markermodel.h"

class SearchHelper
{
public:

    template<class T>
    inline static T* FindInList(QList<T> list_to_search, quint64 id)
    {
        auto it = find_if(list_to_search.begin(),list_to_search.end(), [&id](const ViewElement& element) {
            return element.GetTaskId() == id;
        });

        if (list_to_search.end() != it)
            return it;

        //TODO: Implement proper Exception Class
        throw "ERROR";
    }



    inline static MarkerModel* FindInList(QList<MarkerModel> list_to_search, quint64 id)
    {
        auto it = find_if(list_to_search.begin(),list_to_search.end(), [id](const MarkerModel& element) {
            return element.GetNumber() == id;
        });

        if (list_to_search.end() != it)
            return it;

        //TODO: Implement proper Exception Class
        throw "ERROR";
    }






};

#endif // SEARCHHELPER_H

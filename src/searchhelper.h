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
    inline static T* FindInList(QList<T>* list_to_search, quint64 id)
    {
        int i = 0;
        while ((*list_to_search)[i].GetElementId() != id)
        {
            i++;

        }
        return static_cast<T*>(&(*list_to_search)[i]);


        //TODO: Implement proper Error Handling
        //  throw "ERROR";
    }




    inline static MarkerModel* FindInList(QList<MarkerModel>* list_to_search, quint64 id)
    {
        int i = 0;
        while ((*list_to_search)[i].GetId() != id)
        {
            i++;

        }
        return &(*list_to_search)[i];


        //TODO: Implement proper Error Handling
        throw "ERROR";
    }






};

#endif // SEARCHHELPER_H

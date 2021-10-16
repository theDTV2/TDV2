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

    /**
     * Template function to search in ViewElement list.
     * Returns nullptr, when nothing is found
     */

    static inline QString error_message_to_throw_ = "Couldn't find element, that should have been previously created.";

    template<class T>
    inline static T* FindInList(QList<T>* list_to_search, quint64 id)
    {
        //If the list is empty, we return nullptr
        if (list_to_search->isEmpty())
            throw error_message_to_throw_;

        int i = 0;
        while ((*list_to_search)[i].GetElementId() != id)
        {
            i++;

            //If we are over bound, we return nullptr
            if (list_to_search->count() == i)
                throw error_message_to_throw_;

        }

        return static_cast<T*>(&(*list_to_search)[i]);

    }



    /**
     * function to search in MarkerModel list.
     * Returns nullptr, when nothing is found
     */
    inline static MarkerModel* FindInList(QList<MarkerModel>* list_to_search, quint64 id)
    {
        //If the list is empty, we return nullptr
        if (list_to_search->isEmpty())
            throw error_message_to_throw_;

        int i = 0;
        while ((*list_to_search)[i].GetId() != id)
        {
            i++;

            //If we are over bound, we return nullptr
            if (list_to_search->count() == i)
                throw error_message_to_throw_;
        }

        return &(*list_to_search)[i];
    }






};

#endif // SEARCHHELPER_H

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
static T FindInList(QList<T> list_to_search, quint64 id);
};

#endif // SEARCHHELPER_H

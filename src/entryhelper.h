#ifndef ENTRYHELPER_H
#define ENTRYHELPER_H

#include "queuemodel.h"
#include "taskmodel.h"
#include "useragentmodel.h"
#include "handlermodel.h"
#include "markermodel.h"
#include "searchhelper.h"

class EntryHelper
{
public:

    static QString GetStringAtPosition(const QString& entry,quint8 position) ;

    template<class T>
    static T GetVariableAtPositionInGivenEntry(const QString& entry,quint8 position) ;

};

#endif // ENTRYHELPER_H

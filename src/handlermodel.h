#ifndef HANDLERMODEL_H
#define HANDLERMODEL_H
#include <QtGlobal>
#include <QString>
#include <QList>
#include <QSharedPointer>



#include "viewelement.h"


class HandlerModel : public ViewElement
{
public:
    HandlerModel(QString name);
    void AddEnter(quint64 time);
    void AddExit(quint64 time);


private:
    quint64 last_time_;
};

#endif // HANDLERMODEL_H

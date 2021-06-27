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
    void addEnter(quint64 time);
    void addExit(quint64 time);


private:
    quint64 m_lastTime;
};

#endif // HANDLERMODEL_H

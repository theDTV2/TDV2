#ifndef TASKMODEL_H
#define TASKMODEL_H
#include <QtGlobal>
#include <QString>
#include <QList>
#include <QSharedPointer>

#include "viewelement.h"


class TaskModel : public ViewElement
{
public:
    TaskModel(QString name);

    void setPriority(QString newPriority);
    QString getPrority();

    void addStart(quint64 startTime);
    void addStop(quint64 stopTime);

private:
    QString m_priority;
    quint64 m_lenght;

    quint64 m_startTime = 0;
};

#endif // TASKMODEL_H

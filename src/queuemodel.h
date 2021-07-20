#ifndef QUEUEMODEL_H
#define QUEUEMODEL_H
#include <QtGlobal>
#include <QString>
#include <QList>
#include <QSharedPointer>


#include "viewelement.h"

class QueueModel : public ViewElement
{
public:
    QueueModel(QString name);

    void AddQueueHeight(quint64 newTime);
    void RemoveQueueHeight(quint64 newTime);


private:
    quint64 last_time_ = 0;
    quint16 current_height_ = 0;
    void SetQueueHeight(quint64 start_time, quint64 end_time, quint16 height);
};
#endif // QUEUEMODEL_H

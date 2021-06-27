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

    void addQueueHeight(quint64 newTime);
    void remoteQueueHeight(quint64 newTime);


private:
    quint64 m_lastTime = 0;
    quint64 m_currentheight = 0;
    void setQueueHeight(quint64 startTime, quint64 endTime, quint16 height);
};
#endif // QUEUEMODEL_H

#ifndef VIEWELEMENT_H
#define VIEWELEMENT_H
#include <QtGlobal>
#include <QString>
#include <QList>
#include <QSharedPointer>

#include "datapair.h"



using namespace std;
class ViewElement
{
public:
    ViewElement(QString name);

    void setName (QString newName);
    void setTime(quint64 toSet);

    QString getName();
    quint64 getTime();

    void clearList();

    void addToList(quint64 startTime, quint64 endTime);
    void addToList(quint64 startTime, quint64 endTime, quint16 height);

    QList<DataPair>* getList();

    void setCreationTime(quint64 creationTime);
    quint64 getCreationTime();

    void setTaskId(quint64 taskId);
    quint16 getTaskId();

private:
    QString m_name;
    quint16 m_taskId;
    QList<DataPair> m_entries;
    quint64 m_creationTime;

};

#endif // VIEWELEMENT_H

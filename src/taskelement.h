#ifndef TASKELEMENT_H
#define TASKELEMENT_H
#include <QtGlobal>
#include <QString>
#include <QList>
#include <QSharedPointer>

#include "datapair.h"



using namespace std;
class TaskElement
{
public:
    TaskElement(QString name);

    void setName (QString newName);
    void setTime(quint64 toSet);

    QString getName();
    quint64 getTime();

    void clearList();

    void addToList(quint64 startTime, quint64 endTime);
    void addToList(quint64 startTime, quint64 endTime, quint16 height);

    QList<DataPair>* getList();


private:
    QString m_name;
    QList<DataPair> m_entries;

};

#endif // TASKELEMENT_H

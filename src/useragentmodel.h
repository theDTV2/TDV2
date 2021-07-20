#ifndef USERAGENTMODEL_H
#define USERAGENTMODEL_H
#include <QtGlobal>
#include <QString>
#include <QList>
#include <QSharedPointer>


#include "viewelement.h"


class UserAgentModel : public ViewElement
{
public:
    UserAgentModel(QString name);
    UserAgentModel(QString name, quint16 id);

    void AddEnter(quint64 time);
    void AddExit(quint64 time);


private:
    quint64 last_time_;
};



#endif // USERAGENTMODEL_H

#ifndef MARKERMODEL_H
#define MARKERMODEL_H
#include <QColor>
#include <QtGlobal>
#include <QString>
#include <QSharedPointer>

#include "markerentry.h"

class MarkerModel
{
public:
    MarkerModel(const QString& name, quint16 id);

    void SetName(const QString& newName);
    QString GetName() const;
    void SetId(quint64 id);
    quint64 GetId() const;

    QList<MarkerEntry> GetEntries();
    void ClearEntries();


    void AddEntry(quint64 position);

    void SetColorOfLast(QColor new_color);

    void AddStringToLast(QString string);
    void SetNumberOfLast(quint64 number);



private:

   QString name_ = "";
   quint16 id_;

   QList<MarkerEntry> entries_ = QList<MarkerEntry>();


};

#endif // MARKERMODEL_H

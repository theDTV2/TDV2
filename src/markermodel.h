#ifndef MARKERMODEL_H
#define MARKERMODEL_H
#include <QColor>
#include <QtGlobal>
#include <QString>
#include <QSharedPointer>


class MarkerModel
{
public:
    MarkerModel(QString name, quint64 position, QColor color, quint16 id);

    void SetPosition(quint64 newTime);
    quint64 GetPosition() const;

    void SetColor(QColor newColor);
    QColor GetColor() const;

    void SetName(QString newName);
    QString GetName() const;

    void AddString(QString string);
    void ClearStrings();
    QStringList* GetStrings();

    void SetNumber(quint64 number);
    quint64 GetNumber() const;

    void SetId(quint64 id);
    quint64 GetId() const;



private:

   QString name_;
   quint64 position_;
   QColor  color_;
   quint64 number_;
   QStringList strings_;
   quint16 id_;

};

#endif // MARKERMODEL_H

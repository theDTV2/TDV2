#ifndef MARKERMODEL_H
#define MARKERMODEL_H
#include <QColor>
#include <QtGlobal>
#include <QString>
#include <QSharedPointer>


class MarkerModel
{
public:
    MarkerModel(QString name, quint64 position, QColor color);

    void SetPosition(quint64 newTime);
    quint64 GetPosition();

    void SetColor(QColor newColor);
    QColor GetColor();

    void SetName(QString newName);
    QString GetName();

    void AddString(QString string);
    void ClearStrings();
    QStringList* GetStrings();

    void SetNumber(quint64 number);
    quint64 GetNumber();


private:
   QString name_;
   quint64 position_;
   QColor  color_;
   quint64 number_;
   QStringList strings_;

};

#endif // MARKERMODEL_H

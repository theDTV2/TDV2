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

    void setPosition(quint64 newTime);
    quint64 getPosition();

    void setColor(QColor newColor);
    QColor getColor();

    void setName(QString newName);
    QString getName();

    void addString(QString string);
    void clearStrings();
    QStringList* getStrings();

    void setNumber(quint64 number);
    quint64 getNumber();


private:
   QString m_name;
   quint64 m_position;
   QColor  m_color;
   quint64 m_number;
   QStringList m_strings;

};

#endif // MARKERMODEL_H

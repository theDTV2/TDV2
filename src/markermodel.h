#ifndef MARKERMODEL_H
#define MARKERMODEL_H
#include <QColor>
#include <QtGlobal>
#include <QString>



class Markermodel
{
public:
    Markermodel(QString name, quint64 position, QColor color);

    void setPosition(quint64 newTime);
    quint64 getPosition();

    void setColor(QColor newColor);
    QColor getColor();

    void setName(QString newName);
    QString getName();

private:
   QString m_name;
   quint64 m_position;
   QColor  m_color;
};

#endif // MARKERMODEL_H

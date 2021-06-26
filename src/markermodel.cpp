#include "markermodel.h"

Markermodel::Markermodel(QString name, quint64 position, QColor color)
    :m_name(name),m_position(position),m_color(color)
{

}


void Markermodel::setPosition(quint64 newPosition)
{
    m_position = newPosition;
}
quint64 Markermodel::getPosition()
{
    return m_position;
}

void Markermodel::setColor(QColor newColor)
{
    m_color = newColor;
}
QColor Markermodel::getColor()
{
    return m_color;
}

void Markermodel::setName(QString newName)
{
    m_name = newName;
}
QString Markermodel::getName()
{
    return m_name;
}

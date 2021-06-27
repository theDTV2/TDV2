#include "markermodel.h"

MarkerModel::MarkerModel(QString name, quint64 position, QColor color)
    :m_name(name),m_position(position),m_color(color)
{

}


void MarkerModel::setPosition(quint64 newPosition)
{
    m_position = newPosition;
}
quint64 MarkerModel::getPosition()
{
    return m_position;
}

void MarkerModel::setColor(QColor newColor)
{
    m_color = newColor;
}
QColor MarkerModel::getColor()
{
    return m_color;
}

void MarkerModel::setName(QString newName)
{
    m_name = newName;
}

QString MarkerModel::getName()
{
    return m_name;
}

void MarkerModel::addString(QString string)
{
    m_strings.append(string);
}

void MarkerModel::clearStrings()
{
    m_strings.clear();
}

QStringList* MarkerModel::getStrings()
{
    return &m_strings;
}

void MarkerModel::setNumber(quint64 number)
{
    m_number = number;
}

quint64 MarkerModel::getNumber()
{
    return m_number;
}

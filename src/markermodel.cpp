#include "markermodel.h"

MarkerModel::MarkerModel(QString name, quint64 position, QColor color)
    :name_(name),position_(position),color_(color)
{

}


void MarkerModel::SetPosition(quint64 new_position)
{
    position_ = new_position;
}
quint64 MarkerModel::GetPosition()
{
    return position_;
}

void MarkerModel::SetColor(QColor new_color)
{
    color_ = new_color;
}
QColor MarkerModel::GetColor()
{
    return color_;
}

void MarkerModel::SetName(QString new_name)
{
    name_ = new_name;
}

QString MarkerModel::GetName()
{
    return name_;
}

void MarkerModel::AddString(QString string)
{
    strings_.append(string);
}

void MarkerModel::ClearStrings()
{
    strings_.clear();
}

QStringList* MarkerModel::GetStrings()
{
    return &strings_;
}

void MarkerModel::SetNumber(quint64 number)
{
    number_ = number;
}

quint64 MarkerModel::GetNumber()
{
    return number_;
}

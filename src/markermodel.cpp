#include "markermodel.h"

MarkerModel::MarkerModel(QString name, quint64 position, QColor color, quint16 id)
    :name_(name),position_(position),color_(color), id_(id)
{

}


void MarkerModel::SetPosition(quint64 new_position)
{
    position_ = new_position;
}
quint64 MarkerModel::GetPosition() const
{
    return position_;
}

void MarkerModel::SetColor(QColor new_color)
{
    color_ = new_color;
}
QColor MarkerModel::GetColor() const
{
    return color_;
}

void MarkerModel::SetName(QString new_name)
{
    name_ = new_name;
}

QString MarkerModel::GetName() const
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

QStringList *MarkerModel::GetStrings()
{
    return &strings_;
}

void MarkerModel::SetNumber(quint64 number)
{
    number_ = number;
}

quint64 MarkerModel::GetNumber() const
{
    return number_;
}

void MarkerModel::SetId(quint64 id)
{
    id_ = id;
}

quint64 MarkerModel::GetId() const
{
    return id_;
}

#include "markermodel.h"

MarkerModel::MarkerModel(QString name, quint16 id)
    :name_(name), id_(id)
{

}




void MarkerModel::AddPosition(quint64 new_position)
{
    positions_.append(new_position);
}
QList<quint64> MarkerModel::GetPositions()
{
    return positions_;
}

void MarkerModel::ClearPositions()
{
    positions_.clear();
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

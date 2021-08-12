#include "markermodel.h"

MarkerModel::MarkerModel(QString name, quint16 id)
    :name_(name), id_(id)
{

}

void MarkerModel::SetName(QString new_name)
{
    name_ = new_name;
}

QString MarkerModel::GetName() const
{
    return name_;
}

void MarkerModel::SetId(quint64 id)
{
    id_ = id;
}

quint64 MarkerModel::GetId() const
{
    return id_;
}

QList<MarkerEntry> MarkerModel::GetEntries()
{
    return entries_;
}

void MarkerModel::ClearEntries()
{
    entries_.clear();
}

void MarkerModel::AddEntry(quint64 position)
{
    entries_.append(MarkerEntry(position));
}

void MarkerModel::SetColorOfLast(QColor new_color)
{
    entries_.last().SetColor(new_color);
}

void MarkerModel::AddStringToLast(QString string)
{
    entries_.last().AddString(string);
}

void MarkerModel::SetNumberOfLast(quint64 number)
{
    entries_.last().SetNumber(number);
}



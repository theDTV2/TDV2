#include "markerentry.h"

MarkerEntry::MarkerEntry(quint64 position)
    :position_(position)
{

}

void MarkerEntry::AddString(QString string)
{
    strings_.append(string);
}

void MarkerEntry::ClearStrings()
{
    strings_.clear();
}

QStringList *MarkerEntry::GetStrings()
{
    return &strings_;
}

void MarkerEntry::SetColor(QColor new_color)
{
    color_ = new_color;
}

QColor MarkerEntry::GetColor()
{
    return color_;
}

void MarkerEntry::SetNumber(qint64 number)
{
    number_ = number;
}

qint64 MarkerEntry::GetNumber()
{
    return number_;
}

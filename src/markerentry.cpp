#include "markerentry.h"

/**
 * @brief Marker Entry for a Marker Model
 * @param position position of marker
 */
MarkerEntry::MarkerEntry(quint64 position)
    :position_(position), number_(0)
{
}

/**
 * @brief getter
 * @return position
 */
quint64 MarkerEntry::GetPosition()
{
    return position_;
}

/**
 * @brief Adds given string to stringlist
 * @param string string to add to list
 */
void MarkerEntry::AddString(QString string)
{
    strings_.append(string);
}

/**
 * @brief clear strings saved in entry
 */
void MarkerEntry::ClearStrings()
{
    strings_.clear();
}

/**
 * @brief getter
 * @return strings
 */
QStringList *MarkerEntry::GetStrings()
{
    return &strings_;
}

/**
 * @brief Setter
 * @param new_color color to use
 */
void MarkerEntry::SetColor(QColor new_color)
{
    color_ = new_color;
}

/**
 * @brief getter
 * @return color
 */
QColor MarkerEntry::GetColor()
{
    return color_;
}

/**
 * @brief setter
 * @param number number to set
 */
void MarkerEntry::SetNumber(qint64 number)
{
    number_ = number;
}

/**
 * @brief getter
 * @return number
 */
qint64 MarkerEntry::GetNumber()
{
    return number_;
}

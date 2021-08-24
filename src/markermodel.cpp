#include "markermodel.h"

/**
 * @brief constructs new marker model
 * @param name name to set
 * @param id id to set
 */
MarkerModel::MarkerModel(const QString& name, quint16 id)
    :name_(name), id_(id)
{

}

/**
 * @brief setter
 * @param new_name new name to set
 */
void MarkerModel::SetName(const QString& new_name)
{
    name_ = new_name;
}

/**
 * @brief getter
 * @return name
 */
QString MarkerModel::GetName() const
{
    return name_;
}

/**
 * @brief setter
 * @param id  id to set
 */
void MarkerModel::SetId(quint64 id)
{
    id_ = id;
}

/**
 * @brief getter
 * @return id
 */
quint64 MarkerModel::GetId() const
{
    return id_;
}

/**
 * @brief getter
 * @return entries in model
 */
QList<MarkerEntry> MarkerModel::GetEntries()
{
    return entries_;
}

/**
 * @brief clear all entries
 */
void MarkerModel::ClearEntries()
{
    entries_.clear();
}

/**
 * @brief add new entry to marker model
 * @param position pos to set on
 */
void MarkerModel::AddEntry(quint64 position)
{
    entries_.append(MarkerEntry(position));
}

/**
 * @brief sets color of last MarkerEntry created & added
 * @param new_color color to set
 */
void MarkerModel::SetColorOfLast(QColor new_color)
{
    entries_.last().SetColor(new_color);
}

/**
 * @brief Adds string to last MarkerEntry created & added
 * @param string
 */
void MarkerModel::AddStringToLast(QString string)
{
    entries_.last().AddString(string);
}

/**
 * @brief sets number of last MarkerEntry created & added
 * @param string
 */
void MarkerModel::SetNumberOfLast(quint64 number)
{
    entries_.last().SetNumber(number);
}



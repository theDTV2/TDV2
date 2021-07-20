#include "entryhelper.h"


/*
 * Get given Variable at position (stating at 0) from given entry
 * specialized for QString
 */
template<>
QString EntryHelper::GetVariableAtPositionInGivenEntry<QString>(QString entry,quint8 position)
{

    return GetStringAtPosition(entry, position);
}

/*
 * Get given Variable at position (stating at 0) from given entry
 * specialized for quint64
 */
template<>
quint64 EntryHelper::GetVariableAtPositionInGivenEntry<quint64>(QString entry,quint8 position)
{

    return GetStringAtPosition(entry, position).toULongLong();

}

/*
 * Get given Variable at position (stating at 0) from given entry
 * specialized for qint64
 */
template<>
qint64 EntryHelper::GetVariableAtPositionInGivenEntry<qint64>(QString entry,quint8 position)
{

    return GetStringAtPosition(entry, position).toLongLong();

}

QString EntryHelper::GetStringAtPosition(QString entry, quint8 positison)
{
    //Iterate through Entry until we get to the desired variable
    int current_variable_position = 0;
    int current_position_In_Entry = 0;
    while(current_variable_position < positison)
    {
        if (entry[current_position_In_Entry] == ' ')
            current_variable_position++;
        current_position_In_Entry ++;
    }

    QString read_var = "";

    while (current_variable_position != entry.length() || entry[current_variable_position] != ' ')
    {
        read_var.append(entry[current_variable_position]);
        current_variable_position++;
    }
    return read_var;
}

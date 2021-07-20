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
 * specialized for quint64 (u long long)
 */
template<>
quint64 EntryHelper::GetVariableAtPositionInGivenEntry<quint64>(QString entry,quint8 position)
{

    return GetStringAtPosition(entry, position).toULongLong();

}

/*
 * Get given Variable at position (stating at 0) from given entry
 * specialized for quint32 (uint)
 */
template<>
quint32 EntryHelper::GetVariableAtPositionInGivenEntry<quint32>(QString entry,quint8 position)
{

    return GetStringAtPosition(entry, position).toULong();

}

/*
 * Get given Variable at position (stating at 0) from given entry
 * specialized for quint16 (ushort)
 */
template<>
quint16 EntryHelper::GetVariableAtPositionInGivenEntry<quint16>(QString entry,quint8 position)
{

    return GetStringAtPosition(entry, position).toUShort();

}



/*
 * Get given Variable at position (stating at 0) from given entry
 * specialized for qint64 (long long)
 */

template<>
qint64 EntryHelper::GetVariableAtPositionInGivenEntry<qint64>(QString entry,quint8 position)
{

    return GetStringAtPosition(entry, position).toLongLong();

}

/*
 * Get given Variable at position (stating at 0) from given entry
 * specialized for qint32 (long )
 */

template<>
qint32 EntryHelper::GetVariableAtPositionInGivenEntry<qint32>(QString entry,quint8 position)
{

    return GetStringAtPosition(entry, position).toLong();

}
QString EntryHelper::GetStringAtPosition(QString entry, quint8 position)
{
    //Iterate through Entry until we get to the desired variable
    int current_variable_position = 0;
    int current_position_In_Entry = 0;
    while(current_variable_position < position)
    {
        if (entry[current_position_In_Entry] == ' ')
            current_variable_position++;
        current_position_In_Entry++;
    }

    QString read_var = "";

    while (current_position_In_Entry != entry.length() && entry[current_position_In_Entry] != ' ')
    {
        read_var.append(entry[current_position_In_Entry]);
        current_position_In_Entry++;
    }
    return read_var;
}

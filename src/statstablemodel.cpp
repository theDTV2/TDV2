#include "statstablemodel.h"

/**
 * Construction override of QAbstractTableModel
 */
StatsTableModel::StatsTableModel(QObject *parent) : QAbstractTableModel(parent)
{}

/**
 * @brief Implements rowCount
 * @param parent not used
 * @return row count used in table
 */
int StatsTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return data_vector_.count();
}

/**
 * @brief Implements columnCount
 * @param parent not used
 * @return column count used in table
 */
int StatsTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 6;
}

/**
 * @brief Implements data function. This function is called by the table view to populate the table
 * @param index position of value in table
 * @param role data role
 * @return
 */
QVariant StatsTableModel::data(const QModelIndex &index, int role) const
{
    //std::get doesnt like variables, so the index of each element has to be decided beforehand

    if (data_vector_.isEmpty())
        return QVariant();


    if (role == Qt::DisplayRole)
    {
        switch (index.column()) {
        case 0:
            return QVariant(std::get<0>(data_vector_.at(index.row())));
        case 1:
            return QVariant(std::get<1>(data_vector_.at(index.row())));
        case 2:
            return QVariant(std::get<2>(data_vector_.at(index.row())));
        case 3:
            return QVariant(std::get<3>(data_vector_.at(index.row())));
        case 4:
            return QVariant(std::get<4>(data_vector_.at(index.row())));
        case 5:
            return QVariant(std::get<5>(data_vector_.at(index.row())));
        }
    }

    //Return invalid QVariant(), in case we somehow dont break earlier
    return QVariant();
}

/**
 * @brief Implements headerData
 * @param section header section to use
 * @param orientation orientation to use
 * @param role data role
 * @return
 */
QVariant StatsTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Orientation::Horizontal && role == Qt::DisplayRole)
    {
        switch (section) {
        case 0:
            return QVariant("Task name");
        case 1:
            return QVariant("#executions");
        case 2:
            return QVariant("freq. executions");
        case 3:
            return QVariant("shortest");
        case 4:
            return QVariant("longest");
        case 5:
            return QVariant("average");

        }

    }

    return QVariant();

}

/**
 * @brief clears all data used
 */
void StatsTableModel::ClearEntries()
{
    data_vector_.clear();
}

/**
 * @brief Add entry to data_vector
 * @param task_name Name of Task
 * @param number_of_executions Amount of Executions
 * @param executions_per_second Executions per Second
 * @param min_exec_lenght Minimum Exection Lenght
 * @param max_exec_lenght Maximum Execution Lenght
 * @param average_exec_lenght Averag Execution Lenght
 */
void StatsTableModel::AddEntry(QString task_name, quint32 number_of_executions, qreal executions_per_second, qreal min_exec_lenght, qreal max_exec_lenght, qreal average_exec_lenght)
{
    data_vector_.append(std::tuple<QString,QString,QString, QString, QString, QString>(task_name,
                                                                                       QString::number(number_of_executions,'f',1),
                                                                                       QString::number(executions_per_second,'f',1) + " /s",
                                                                                       QString::number(min_exec_lenght,'f',5) + " ms",
                                                                                       QString::number(max_exec_lenght,'f',5) + " ms",
                                                                                       QString::number(average_exec_lenght,'f',5) + "  ms"));
    endResetModel();
}

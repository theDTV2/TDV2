#ifndef STATSTABLEMODEL_H
#define STATSTABLEMODEL_H

#include <QAbstractTableModel>

class StatsTableModel : public QAbstractTableModel
{
    Q_OBJECT


public:
    explicit StatsTableModel(QObject *parent = nullptr);

    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    void ClearEntries();
    void AddEntry(QString task_name, quint32 number_of_executions, qreal executions_per_second, qreal min_exec_lenght, qreal max_exec_lenght, qreal average_exec_lenght);

private:
    QVector<std::tuple<QString,QString,QString, QString, QString, QString>> data_vector_;

};

#endif // STATSTABLEMODEL_H

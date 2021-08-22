#ifndef STATS_H
#define STATS_H

#include <QDialog>
#include <QChart>
#include <QtConcurrent/QtConcurrent>
#include <QFutureWatcher>
#include <QTableView>
#include <qchartview.h>
#include "statistichelper.h"

#include "graphicdrawer.h"

namespace Ui {
class Stats;
}

class Stats : public QDialog
{
    Q_OBJECT

public:
    explicit Stats(QWidget *parent = nullptr);
    ~Stats();

private:
    Ui::Stats *ui;



    QChart chart_;
    static inline bool thread_is_running_ = false;
    static inline QFutureWatcher<void> watcher_ = QFutureWatcher<void>();
    static inline QFuture<void> future_ =  QFuture<void>();


    void StartUpdate();

    static inline QChartView* load_chart_view_ = nullptr;
    static inline QTableView* stats_table_view_ = nullptr;


    bool only_use_selected_viewelement_ = false;
    bool only_use_visible_in_viewport_ = false;


private slots:
    void finishedCalculating();
    void on_toggleViewableData_clicked(bool checked);
};

#endif // STATS_H

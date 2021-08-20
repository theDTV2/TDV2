#ifndef STATS_H
#define STATS_H

#include <QDialog>
#include <QtConcurrent/QtConcurrent>
#include <QFutureWatcher>

#include "statistichelper.h"

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


    static void StartUpdate();


public slots:
    static void finishedCalculating();

private slots:
    void on_testUpdate_clicked();

};

#endif // STATS_H

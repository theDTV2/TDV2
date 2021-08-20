#include "stats.h"
#include "ui_stats.h"

Stats::Stats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stats)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::WindowCloseButtonHint, false);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &StartUpdate);
    timer->start(2000);

    connect (&watcher_, &QFutureWatcher<void>::finished, this, &Stats::finishedCalculating);

}

Stats::~Stats()
{
    delete ui;
}

void Stats::StartUpdate()
{
    if (thread_is_running_)
        return;


    future_ = QtConcurrent::run(&StatisticHelper::GenerateData);
    watcher_.setFuture(future_);

    thread_is_running_ = true;
}



void Stats::finishedCalculating()
{
    thread_is_running_ = false;

}

void Stats::on_testUpdate_clicked()
{

}






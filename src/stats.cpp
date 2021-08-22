#include "stats.h"
#include "ui_stats.h"

Stats::Stats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stats)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::WindowCloseButtonHint, false);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Stats::StartUpdate);
    timer->start(2000);

    connect (&watcher_, &QFutureWatcher<void>::finished, this, &Stats::finishedCalculating);

    load_chart_view_ = ui->leftChart;
    execs_chart_view_ = ui->rightChart;

}

Stats::~Stats()
{
    delete ui;
}

void Stats::StartUpdate()
{
    if (thread_is_running_)
        return;

    StatisticHelper::PopulateVariables(only_use_visible_in_viewport_,
                                       GraphicDrawer::GetSelectedViewElement());

    future_ = QtConcurrent::run(&StatisticHelper::GenerateData);
    watcher_.setFuture(future_);

    thread_is_running_ = true;
}



void Stats::finishedCalculating()
{
    thread_is_running_ = false;
    load_chart_view_->setChart(StatisticHelper::GetLoadChart());


    ui->topLabel->setText(StatisticHelper::GetLeftLabel());
    //ui->rightLabel->setText(StatisticHelper::GetRightLabel());
}


void Stats::on_toggleViewableData_clicked(bool checked)
{
    only_use_visible_in_viewport_ = checked;
}

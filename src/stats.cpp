#include "stats.h"
#include "ui_stats.h"

Stats::Stats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stats)
{
    ui->setupUi(this);
    //this->setWindowFlag(Qt::WindowCloseButtonHint, false);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Stats::StartUpdate);
    timer->start(500);

    connect (&watcher_, &QFutureWatcher<void>::finished, this, &Stats::finishedCalculating);

    load_chart_view_ = ui->leftChart;
    stats_table_view_ = ui->tableView;
    stats_table_view_->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

Stats::~Stats()
{
    delete ui;
}

void Stats::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);

    emit DestoryingProcess();
    delete this;

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

    QChart* new_chart = StatisticHelper::GetLoadChart();

    if (new_chart != load_chart_view_->chart())
        load_chart_view_->setChart(new_chart);


    stats_table_view_->setModel(StatisticHelper::GetTableModel());

    ui->mainLabel->setText(StatisticHelper::GetLeftLabel());

}


void Stats::on_toggleViewableData_clicked(bool checked)
{
    only_use_visible_in_viewport_ = checked;
}



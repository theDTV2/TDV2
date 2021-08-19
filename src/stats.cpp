#include "stats.h"
#include "ui_stats.h"

Stats::Stats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stats)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::WindowCloseButtonHint, false);
}

Stats::~Stats()
{
    delete ui;
}

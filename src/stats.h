#ifndef STATS_H
#define STATS_H

#include <QDialog>

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
};

#endif // STATS_H

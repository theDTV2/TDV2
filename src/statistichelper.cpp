#include "statistichelper.h"




void StatisticHelper::PopulateVariables(bool only_use_selected_viewelement, bool only_use_visible_in_viewport, QString selected_view_element)
{

    chart_ = new QChart();


    only_use_selected_viewelement_ = only_use_selected_viewelement;
    only_use_visible_in_viewport_ = only_use_visible_in_viewport;
    if (only_use_selected_viewelement_)
    {
       selected_view_element_ = selected_view_element;
    }

    if (only_use_visible_in_viewport_)
    {
        left_boundary_ = GraphicDrawer::GetViewPortLeft();
        right_boundary_ = GraphicDrawer::GetViewPortRight();
    }

}

void StatisticHelper::GenerateData()
{
    if (only_use_visible_in_viewport_)
    {


    }

}

QString StatisticHelper::GetRightLabel()
{
    return right_label_;
}

QString StatisticHelper::GetLeftLabel()
{
    return left_label_;
}

QChart *StatisticHelper::GetChart()
{
    /*QBarSet *set0 = new QBarSet("Jane");
    QBarSet *set1 = new QBarSet("John");
    QBarSet *set2 = new QBarSet("Axel");
    QBarSet *set3 = new QBarSet("Mary");
    QBarSet *set4 = new QBarSet("Samantha");

    *set0 << QRandomGenerator::global()->bounded(256) << 2 << 3 << 4 << 5 << 6;
    *set1 << QRandomGenerator::global()->bounded(256) << 0 << 0 << 4 << 0 << 7;
    *set2 << QRandomGenerator::global()->bounded(256) << 5 << 8 << 13 << 8 << 5;
    *set3 << QRandomGenerator::global()->bounded(256) << 6 << 7 << 3 << 4 << 5;
    *set4 << QRandomGenerator::global()->bounded(256) << 7 << 5 << 3 << 1 << 2;
    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);


    chart_->removeAllSeries();
    chart_->addSeries(series);
    chart_->setTitle("Simple barchart example");

    QStringList categories;
    categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart_->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,256);
    chart_->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);


    chart_->legend()->setVisible(true);
    chart_->legend()->setAlignment(Qt::AlignBottom);
*/
    return chart_;
}

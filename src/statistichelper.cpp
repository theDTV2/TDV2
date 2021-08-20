#include "statistichelper.h"




void StatisticHelper::PopulateVariables(bool only_use_visible_in_viewport, QString selected_view_element)
{
    drawn_view_elements_ = GraphicDrawer::GetDrawnElements();

    //If there are no drawn elements, we instantly leave
    if(drawn_view_elements_.empty())
        return;

    //Create Series & Chart in this to preven the UI-Thread from exploding
    series_ = new QBarSeries();
    chart_ = new QChart();



    only_use_visible_in_viewport_ = only_use_visible_in_viewport;
    if (only_use_visible_in_viewport_)
    {
        left_boundary_ = GraphicDrawer::GetViewPortLeft();
        right_boundary_ = GraphicDrawer::GetViewPortRight();
    }

}

void StatisticHelper::GenerateData()
{
    if (drawn_view_elements_.empty())
        return;


    //cleanup
    data_vector_.clear();


    //warning is obsolete since qt6, as QVector now is an wrapper for QList
    data_vector_ = QList<QPair<QString,qreal>>();     // clazy:exclude=inefficient-qlist-soft

    for (auto e : drawn_view_elements_)
    {
        //We only calculate load of tasks
        if (e->GetType() == "Tasks")
        {
            if (!only_use_visible_in_viewport_)
                data_vector_.append(QPair<QString,qreal>(e->GetLabel(),LineModelHelper::GetExecutionTimeFromLineModel(e)));
            else
                data_vector_.append(QPair<QString,qreal>(e->GetLabel(),LineModelHelper::GetExecutionTimeFromLineModel(e,left_boundary_,right_boundary_)));
        }
    }

    max_value_ = AxisManager::GetXAxisLenght();

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
    if (data_vector_.count() == 0)
        return new QChart();


    //generate QSeries
    for (auto &e : data_vector_)
    {
        QBarSet* set = new QBarSet(e.first);
        //convert to %
        *set << (e.second / max_value_)*100;
        series_->append(set);


        //Override the raw value, so that we can use it later
        e.second = (e.second / max_value_)*100;

    }


    chart_->addSeries(series_);
    chart_->setTitle("Load");

    QStringList categories;
    for (auto &e : data_vector_)
        categories << e.first;

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);

    QValueAxis *axisY = new QValueAxis();


    qreal max = 0;
    for (auto &e : data_vector_)
    {
        if (e.second > max)
            max = e.second;
    }

    qDebug("%f",max);
    //Set a slightly higher Y-Range to make it prettier
    axisY->setRange(0,max * 1.2);

    chart_->addAxis(axisY, Qt::AlignLeft);
    series_->attachAxis(axisY);

    chart_->legend()->setVisible(true);
    chart_->legend()->setAlignment(Qt::AlignBottom);


    return chart_;
}

qreal StatisticHelper::GetXLenght()
{
    if (only_use_visible_in_viewport_)
        return right_boundary_ - left_boundary_;
    return AxisManager::GetXAxisLenght();
}

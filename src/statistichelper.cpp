#include "statistichelper.h"


void StatisticHelper::PopulateVariables(bool only_use_visible_in_viewport, QString selected_view_element)
{

    drawn_view_elements_ = GraphicDrawer::GetDrawnElements();


    //If there are no drawn elements, we instantly leave
    if(drawn_view_elements_.empty())
        return;

    //Create Series & Chart in this to preven the UI-Thread from exploding
    load_series_ = new QBarSeries();
    load_chart_ = new QChart();

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
    load_data_.clear();
    data_model_->ClearEntries();


    //warning is obsolete since qt6, as QVector now is an wrapper for QList
    load_data_ = QList<QPair<QString,qreal>>();     // clazy:exclude=inefficient-qlist-soft

    quint32 amount_of_executions = 0;
    qreal average_lenght = 0;
    qreal executions_per_second = 0;


    for (auto e : drawn_view_elements_)
    {
        //We only calculate load of tasks
        if (e->GetType() == "Tasks")
        {
            //generate data for load
            if (!only_use_visible_in_viewport_)
            {
                max_value_ = AxisManager::GetXAxisLenght();

                load_data_.append(QPair<QString,qreal>(e->GetLabel(),LineModelHelper::GetExecutionTimeFromLineModel(e)));
                amount_of_executions = LineModelHelper::GetAmountOfExecutions(e);
                average_lenght = LineModelHelper::GetAverageExecutionLenghtAndMinMax(e);
            }
            else
            {

                max_value_ = right_boundary_ - left_boundary_;

                load_data_.append(QPair<QString,qreal>(e->GetLabel(),LineModelHelper::GetExecutionTimeFromLineModel(e,left_boundary_,right_boundary_)));

                amount_of_executions = LineModelHelper::GetAmountOfExecutions(e,left_boundary_,right_boundary_);
                average_lenght = LineModelHelper::GetAverageExecutionLenghtAndMinMax(e,left_boundary_,right_boundary_);
            }

            executions_per_second = (amount_of_executions / max_value_) * DataAccessor::GetSpeed();

            data_model_->AddEntry(e->GetLabel(),
                                 amount_of_executions,
                                 executions_per_second,
                                 LineModelHelper::GetLastMinLenght() / DataAccessor::GetSpeed() * 1000,
                                 LineModelHelper::GetLastMaxLenght() / DataAccessor::GetSpeed() * 1000,
                                 average_lenght / DataAccessor::GetSpeed() * 1000);
        }

    }


    //Set left label according to variables
    if (only_use_visible_in_viewport_)
    {
        if (DataAccessor::GetSpeed() == 0)
            top_label_ =  "Load between " + QString::number(left_boundary_ ,'f',0) + " ticks and " + QString::number(right_boundary_,'f',0) + " ticks.";
        else
            top_label_ =  "Load between " + QString::number((left_boundary_ / DataAccessor::GetSpeed()) * 1000,'f',1) + "ms and " + QString::number((right_boundary_ / DataAccessor::GetSpeed()) * 1000,'f',1) + "ms ";
    }
    else
        top_label_ = "Load for whole timeline";

    max_value_ = AxisManager::GetXAxisLenght();


}


QString StatisticHelper::GetLeftLabel()
{
    return top_label_;
}

QChart *StatisticHelper::GetLoadChart()
{
    //we only check load_data, as we always fill both
    if (load_data_.count() == 0)
        return new QChart();

    //generate QSeries
    for (auto &e : load_data_)
    {
        QBarSet* set = new QBarSet(e.first);
        //convert to %
        *set << (e.second / max_value_)*100;
        load_series_->append(set);

        //Override the raw value, so that we can use it later
        e.second = (e.second / max_value_)*100;

    }

    load_chart_->addSeries(load_series_);
    load_chart_->setTitle("Load");

    QStringList categories;
    for (auto &e : load_data_)
        categories << e.first;

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);

    QValueAxis *axisY = new QValueAxis();

    qreal max = 0;
    for (auto &e : load_data_)
    {
        if (e.second > max)
            max = e.second;
    }

    //Set a slightly higher Y-Range to make it prettier
    axisY->setRange(0,max * 1.2);

    load_chart_->addAxis(axisY, Qt::AlignLeft);
    load_series_->attachAxis(axisY);

    load_chart_->legend()->setVisible(true);
    load_chart_->legend()->setAlignment(Qt::AlignLeft);

    return load_chart_;
}

StatsTableModel* StatisticHelper::GetTableModel()
{
    return data_model_;
}




qreal StatisticHelper::GetXLenght()
{
    if (only_use_visible_in_viewport_)
        return right_boundary_ - left_boundary_;
    return AxisManager::GetXAxisLenght();
}

#include "statistichelper.h"


void StatisticHelper::PopulateVariables(bool only_use_selected_viewelement, bool only_use_visible_in_viewport)
{
    only_use_selected_viewelement_ = only_use_selected_viewelement;
    only_use_visible_in_viewport_ = only_use_visible_in_viewport;

    if (only_use_selected_viewelement_)
    {
        //TODO
    }

    if (only_use_visible_in_viewport_)
    {
        left_boundary_ = GraphicDrawer::GetViewPortLeft();
        right_boundary_ = GraphicDrawer::GetViewPortRight();
    }
}

void StatisticHelper::GenerateData()
{


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
    return chart_;
}

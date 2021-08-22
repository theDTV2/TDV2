#include "linemodelhelper.h"





qreal LineModelHelper::GetExecutionTimeFromLineModel(LineModel *model, qreal start_time, qreal end_time)
{


    qreal result = 0;
    for (auto e : model->GetDrawnElements())
    {
        if (e->rect().left() >= start_time && e->rect().right() <= end_time)
            result += e->rect().width();

    }
    return result;
}




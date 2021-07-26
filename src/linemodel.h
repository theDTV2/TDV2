#ifndef LINEMODEL_H
#define LINEMODEL_H
#include <QtGlobal>
#include "viewelement.h"


class LineModel
{
public:
    LineModel(qreal x, qreal y, qreal lenght);

    void SetOrigin(qreal x, qreal y);

    qreal GetOriginX();
    qreal GetOriginY();

    void SetLenght(qreal to_set);
    qreal GetLenght ();

    void SetDisplayedElement(QList<ViewElement> to_set);
    QList<ViewElement> GetDisplayedElement();


private:
    qreal origin_x_;
    qreal origin_y_;
    qreal lenght_;
    QList<ViewElement> displayed_elements_;


};



#endif // LINEMODEL_H

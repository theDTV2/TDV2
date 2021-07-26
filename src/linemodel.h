#ifndef LINEMODEL_H
#define LINEMODEL_H
#include <QtGlobal>
#include "viewelement.h"


class LineModel
{
public:
    LineModel(qreal left_point, qreal lenght);

    void SetLeftPoint(qreal to_set);
    qreal GetLeftPoint();

    void SetLenght(qreal to_set);
    qreal GetLenght ();

    void SetDisplayedElement(QList<ViewElement> to_set);
    QList<ViewElement> GetDisplayedElement();


private:
    qreal left_point_;
    qreal lenght_;
    QList<ViewElement> displayed_elements_;


};



#endif // LINEMODEL_H

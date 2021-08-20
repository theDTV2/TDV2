#ifndef STATISTICHELPER_H
#define STATISTICHELPER_H
#include <QChart>
#include <QBarSet>
#include <QBarSeries>
#include <qbarcategoryaxis.h>
#include <qvalueaxis.h>
#include <QRandomGenerator>


#include "customqgraphicsview.h"

class StatisticHelper
{
public:
    static void PopulateVariables(bool only_use_selected_viewelement, bool only_use_visible_in_viewport, QString selected_view_element_ = "");
    static void GenerateData();

    static QString GetRightLabel();
    static QString GetLeftLabel();
    static QChart *GetChart();

private:
    static inline QList<LineModel*> drawn_view_elements_ = QList<LineModel*>();
    static inline qreal left_boundary_;
    static inline qreal right_boundary_;
    static inline QString  selected_view_element_;

    static inline QString left_label_;
    static inline QString right_label_;
    static inline QChart* chart_;

    static inline bool only_use_selected_viewelement_;
    static inline bool only_use_visible_in_viewport_;

};

#endif // STATISTICHELPER_H

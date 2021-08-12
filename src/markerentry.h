#ifndef MARKERENTRY_H
#define MARKERENTRY_H
#include <QtGlobal>
#include <QStringList>
#include <QColor>

class MarkerEntry
{
public:
    MarkerEntry(quint64 position);

    quint64 GetPosition();

    void AddString(QString string);
    void ClearStrings();
    QStringList *GetStrings();

    void SetColor(QColor new_color);
    QColor GetColor();

    void SetNumber(qint64 number);
    qint64 GetNumber();


private:
    quint64 position_;
    qint64 number_;
    QStringList strings_;
    QColor color_;
};

#endif // MARKERENTRY_H

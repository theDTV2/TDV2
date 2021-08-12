#ifndef MARKERMODEL_H
#define MARKERMODEL_H
#include <QColor>
#include <QtGlobal>
#include <QString>
#include <QSharedPointer>


class MarkerModel
{
public:
    MarkerModel(QString name, quint16 id);

    void AddPosition(quint64 newTime);
    QList<quint64> GetPositions();
    void ClearPositions();

    void SetColor(QColor newColor);
    QColor GetColor() const;

    void SetName(QString newName);
    QString GetName() const;

    void AddString(QString string);
    void ClearStrings();
    QStringList* GetStrings();

    void SetNumber(quint64 number);
    quint64 GetNumber() const;

    void SetId(quint64 id);
    quint64 GetId() const;



private:

   QString name_ = "";
   QList<quint64> positions_ = QList<quint64>();
   QColor  color_ = Qt::black;
   quint64 number_ = 0;
   QStringList strings_ = QStringList();
   quint16 id_;

};

#endif // MARKERMODEL_H

#ifndef MOUSEZOOMHELPER_H
#define MOUSEZOOMHELPER_H

#include <QObject>
#include <QWheelEvent>

#include <QEvent>

class MouseZoomHelper : public QObject
{
    Q_OBJECT
public:
    explicit MouseZoomHelper(QObject *parent = nullptr);

    void SetAwayFunction(void (*away_function)(void));
    void SetTowardFunction(void (*toward_function)(void));
    void SetResizeFunction(void (*resize_function)(void));
protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
void (*func_away_)(void);
void (*func_towards_)(void);
void (*func_resize_)(void);

signals:

};

#endif // MOUSEZOOMHELPER_H

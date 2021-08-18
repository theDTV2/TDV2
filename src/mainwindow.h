#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graphicsmanager.h"
#include "about.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_actionLoad_from_TDI_File_triggered();

    void on_actionQuit_triggered();


    void on_actionAbout_2_triggered();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H

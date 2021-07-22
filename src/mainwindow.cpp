#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "datareader.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_loadTDV_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Choose TimeDoctor File",
                                                    QDir::homePath(),
                                                    "*.txt *.tdi");

    if (fileName.isEmpty())
        return;

    DataReader::SetPathOfFile(fileName);
    DataReader::ReadTDVFile();
}


void MainWindow::on_testingButton_clicked()
{

GraphicsViewDrawer::SetupScene(ui->mainView);

}


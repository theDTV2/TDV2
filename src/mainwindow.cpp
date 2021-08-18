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




void MainWindow::on_actionLoad_from_TDI_File_triggered()
{
    ProcessTDI();

}


void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}




void MainWindow::on_actionAbout_2_triggered()
{
    About* about = new About(this);
    about->show();
}

void MainWindow::ProcessTDI()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Choose TimeDoctor File",
                                                    QDir::homePath(),
                                                    "*.txt *.tdi");
    if (fileName.isEmpty())
        return;

    DataReader::SetPathOfFile(fileName);
    DataReader::ReadTDVFile();

    GraphicsManager::SetupScene(ui->mainView, ui->labelView);
}


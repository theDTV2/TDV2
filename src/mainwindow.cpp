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

    SetInfoTextBox();
    UpdateSelectorBoxValues();
}



void MainWindow::SetInfoTextBox()
{
    QString value = "";


    if (DataAccessor::GetSpeed() != 0)
        value.append("File: " + DataAccessor::GetId() + " \n");

    if (DataAccessor::GetSpeed() != 0)
        value.append("Speed: " + QString::number(DataAccessor::GetSpeed()) + " \n");


    ui->logData->setText(value);


}

void MainWindow::UpdateSelectorBoxValues()
{
    ui->dataModelSelector->clear();


    if (DataFactory::GetDataModelStrings().count())
        ui->dataModelSelector->setEnabled(true);
    else
        ui->dataModelSelector->setEnabled(false);


    for(auto &e : DataFactory::GetDataModelStrings())
    {
        ui->dataModelSelector->addItem(e);
    }

    ui->dataModelSelector->setCurrentText(DataAccessor::GetId());

}




void MainWindow::on_dataModelSelector_textActivated(const QString &arg1)
{
    DataAccessor::SelectDataModel(arg1);
    GraphicsManager::SetupScene(ui->mainView, ui->labelView);
    SetInfoTextBox();

}


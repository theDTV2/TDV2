#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "datareader.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Stats* stats = new Stats(this);
    stats->move(this->pos().x()+this->width()*1.2,this->pos().y()+100);

    stats->show();

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


    if (!DataAccessor::GetId().isEmpty())
        value.append(DataAccessor::GetId() + " \n");


    if (DataAccessor::GetSpeed() != 0)
        value.append("CPU Speed: " + QString::number(DataAccessor::GetSpeed()) + "\n");
    else
        value.append("No CPU Speed information available \n");

    if (DataAccessor::GetSpeed() != 0)
        value.append("Memory Speed: " + QString::number(DataAccessor::GetMemorySpeed()) + " \n");
    else
        value.append("No Memory Speed information available \n");


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


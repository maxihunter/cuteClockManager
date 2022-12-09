#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget w;
        Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts()) {
            ui->comboBox->addItem(port.portName());
        }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_pressed()
{
    ui->pushButton->setEnabled(false);
    ui->comboBox->setEnabled(false);
}


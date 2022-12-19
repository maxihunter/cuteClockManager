#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QStringList led_modes = { "LED off", "stripRollingRainbow", "stripStaticRainbow",
    "stripCircleRainbow", "stripPulseRainbow", "stripArrowDots",
    "stripArrowOverlap", "stripArrowDotsSec", "stripArrowOverlapSec",
    "stripStaticCustom", "stripPulseCustom", "stripStaticRED" };

    QStringList alarm_modes = { "Alarm off", "Alarm On", "Sunrise mode"};
    QStringList sunrise_prerun_modes = { "60 mins", "30 mins", "15 mins"};

    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    this->setFixedSize(QSize(640, 600));
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    ui->lineEditHsv->setReadOnly(true);

    QWidget w;
    Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts()) {
        ui->comboBox->addItem(port.portName());
    }
    for (auto it = led_modes.begin(); it < led_modes.end() ; it++ ) {
        ui->comboBox_ledmode->addItem(*it);
    }
    for (auto it = alarm_modes.begin(); it < alarm_modes.end() ; it++ ) {
        ui->comboBox_alarmmode->addItem(*it);
    }
    for (auto it = sunrise_prerun_modes.begin(); it < sunrise_prerun_modes.end() ; it++ ) {
        ui->comboBox_sunriseprerun->addItem(*it);
    }

    connect(ui->buttonConnect, &QPushButton::clicked, this, &MainWindow::clickedConnectButton);
    connect(ui->buttonDisconnet, &QPushButton::clicked, this, &MainWindow::clickedDisconnectButton);
    connect(ui->buttonTest, &QPushButton::clicked, this, &MainWindow::clickedTestButton);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clickedConnectButton() {
    serial.setPortName(ui->comboBox->currentText());
    if(!serial.setBaudRate(QSerialPort::Baud9600 , QSerialPort::AllDirections))
        qDebug() << serial.errorString();
    if(!serial.setDataBits(QSerialPort::Data8))
        qDebug() << serial.errorString();
    if(!serial.setParity(QSerialPort::NoParity))
        qDebug() << serial.errorString();
    if(!serial.setFlowControl(QSerialPort::NoFlowControl))
        qDebug() << serial.errorString();
    if(!serial.setStopBits(QSerialPort::OneStop))
        qDebug() << serial.errorString();
    qDebug() << serial.bytesAvailable();

    serial.open(QIODevice::ReadWrite);
    if (serial.isOpen()) {
        qDebug() << "Serial port is open...";
        QByteArray datas = serial.readAll();
    } else {
        QMessageBox::critical(this, "Error", "Serial port \""+ui->comboBox->currentText()+"\" cannot be opened.", QMessageBox::Ok);
        return;
    }
    ui->buttonConnect->setEnabled(false);
    ui->comboBox->setEnabled(false);
    m_clockOperator.setSerial(serial);
}

void MainWindow::clickedDisconnectButton() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Really?", "Are you sure you want to disconnect?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        qDebug() << "Yes was clicked";
        //QApplication::quit();
        serial.close();
    }
}

void MainWindow::clickedTestButton() {
    if (m_clockOperator.testClock()) {
        qDebug() << "m_clockOperator.testClock...OK";
    }
}

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

    ui->spinBox->setMinimum(0);
    ui->spinBox->setMaximum(23);

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
    connect(ui->button_getFromPc, &QPushButton::clicked, this, &MainWindow::clickedGetFromPcButton);
    connect(ui->button_getFromDevice, &QPushButton::clicked, this, &MainWindow::clickedGetFromDeviceButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clickedConnectButton() {
    m_serial.setPortName(ui->comboBox->currentText());
    if(!m_serial.setBaudRate(QSerialPort::Baud9600 , QSerialPort::AllDirections))
        qDebug() << m_serial.errorString();
    if(!m_serial.setDataBits(QSerialPort::Data8))
        qDebug() << m_serial.errorString();
    if(!m_serial.setParity(QSerialPort::NoParity))
        qDebug() << m_serial.errorString();
    if(!m_serial.setFlowControl(QSerialPort::NoFlowControl))
        qDebug() << m_serial.errorString();
    if(!m_serial.setStopBits(QSerialPort::OneStop))
        qDebug() << m_serial.errorString();
    qDebug() << m_serial.bytesAvailable();

    m_serial.open(QIODevice::ReadWrite);
    if (m_serial.isOpen()) {
        qDebug() << "Serial port is open...";
        QByteArray datas = m_serial.readAll();
    } else {
        QMessageBox::critical(this, "Error", "Serial port \""+ui->comboBox->currentText()+"\" cannot be opened.", QMessageBox::Ok);
        return;
    }
    ui->buttonConnect->setEnabled(false);
    ui->comboBox->setEnabled(false);
    m_clockOperator.setSerial(m_serial);
    //m_clockOperator.getClockInfo(&m_clock);
}

void MainWindow::clickedDisconnectButton() {
    if (ui->comboBox->isEnabled())
        return;
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Really?", "Are you sure you want to disconnect?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        qDebug() << "Yes was clicked";
        //QApplication::quit();
        m_serial.close();
        ui->buttonConnect->setEnabled(true);
        ui->comboBox->setEnabled(true);
    }
}

void MainWindow::clickedTestButton() {
    if (m_clockOperator.testClock()) {
        QMessageBox::information(this, "Ok", "Clock connection is OKey",
            QMessageBox::Ok);
        qDebug() << "m_clockOperator.testClock...OK";
    } else {
        QMessageBox::critical(this, "Error", "Clock doesn't responding", QMessageBox::Ok);
        qDebug() << "m_clockOperator.testClock...Failed";
    }
    readClockConfig();
}

void MainWindow::clickedGetFromPcButton()
{
    QTime time = QTime::currentTime();
    ui->timeEdit->setTime(time);
    QDate date = QDate::currentDate();
    ui->dateEdit->setDate(date);
}

void MainWindow::clickedGetFromDeviceButton()
{
    ui->timeEdit->setTime(m_clock.getTime());
    ui->dateEdit->setDate(m_clock.getDate());
}

bool MainWindow::readClockConfig()
{
    if (!m_clockOperator.readClockConfig(&m_clock)) {
        return false;
    }

    return true;
}

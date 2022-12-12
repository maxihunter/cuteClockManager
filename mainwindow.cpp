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

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clickedConnectButton() {
    ui->buttonConnect->setEnabled(false);
    ui->comboBox->setEnabled(false);
}

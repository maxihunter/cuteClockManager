#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QComboBox>
#include <QMessageBox>
#include <QDebug>

#include "cuteclockoperator.h"
#include "cuteclock.h"

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
    void clickedConnectButton();
    void clickedDisconnectButton();
    void clickedTestButton();
    void clickedGetFromPcButton();
    void clickedGetFromDeviceButton();
    
private:
    bool readClockConfig();
    Ui::MainWindow *ui;
    QSerialPort m_serial;
    cuteClock m_clock;
    cuteClockOperator m_clockOperator;
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QComboBox>
#include <QMessageBox>
#include <QDebug>

#include "cuteclockoperator.h"

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

private:
    Ui::MainWindow *ui;
    QSerialPort serial;
    cuteClockOperator m_clockOperator;
};
#endif // MAINWINDOW_H

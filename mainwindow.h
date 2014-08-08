#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "ADXL345Accelerometer.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void updateAccelerometerData();

private:
    Ui::MainWindow *ui;


    ADXL345Accelerometer *accelerometer;
    QTimer dataTimer;
};

#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->accelerometer =  new ADXL345Accelerometer(1,0x53);
    this->accelerometer->SetPowerMode(0x01);

    connect(&this->dataTimer, SIGNAL(timeout()), this, SLOT(updateAccelerometerData()));
    this->dataTimer.start(100);
}

void MainWindow::updateAccelerometerData()
{
    accelerometer->getAccelerationData();
    signed int pitch = this->accelerometer->getPitch();
    signed int roll = this ->accelerometer->getRoll();
    signed int accel_x = this->accelerometer->getAcceleration_X();
    signed int accel_y = this ->accelerometer->getAcceleration_Y();
    signed int accel_z = this ->accelerometer->getAcceleration_Z();
    ui->pitchSlider->setValue((int)pitch);
    ui->rollSlider->setValue((int)roll);
    ui->accelXSlider->setValue((int)accel_x);
    ui->accelYSlider->setValue((int)accel_y);
    ui->accelZSlider->setValue((int)accel_z);

    QString pitchString = "", rollString = "";
    pitchString.append(QString("%1").arg((int)pitch));
    rollString.append(QString("%1").arg((int)roll));
    ui->pitchlcdNumber->display(pitchString);
    ui->rolllcdNumber->display(rollString);

}

MainWindow::~MainWindow()
{
    delete ui;
}

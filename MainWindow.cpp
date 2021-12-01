#include "MainWindow.h"
#include "qnamespace.h"
#include "qwidget.h"
#include <QDebug>
#include <QKeyEvent>
#include <QTime>
#include <ctime>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), timer(new QElapsedTimer)
{
    timerStarted = false;
    presses = 0;
    ui->setupUi(this);
    ui->resetButton->setFocusPolicy(Qt::NoFocus);
    totalPressLabelText = ui->totalPressLabel->text();
    rateLabelText = ui->rateLabel->text();
    timeLabelText = ui->timeLabel->text();

    QObject::connect(ui->resetButton, SIGNAL(clicked()), this, SLOT(reset()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}

void MainWindow::update()
{
    int time;
    if (timerStarted == false)
    {
        timerStarted = true;
        timer->start();
    }
    ++presses;
    time = timer->elapsed();
    ui->timeLabel->setText(timeString(time));
    ui->rateLabel->setText(rateString(time, presses));
    ui->totalPressLabel->setText(totalPressString(presses));
}

void MainWindow::reset()
{
    timerStarted = false;
    presses = 0;
    ui->rateLabel->setText(rateLabelText);
    ui->timeLabel->setText(timeLabelText);
    ui->totalPressLabel->setText(totalPressLabelText);
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space)
    {
        update();
    }
}

QString MainWindow::timeString(unsigned int n)
{
    int s, msecs;
    QString ret = timeLabelText;
    s = n / 1000;
    msecs = n - s * 1000;
    ret.append(QString::number(s));
    ret.append(".");
    ret.append(QString::number(msecs));
    return ret;
}

QString MainWindow::totalPressString(int presses)
{
    QString ret = totalPressLabelText;
    ret.append(QString::number(presses));
    return ret;
}

QString MainWindow::rateString(double timeMsec, double presses)
{
    QString ret = rateLabelText;
    ret.append(QString::number(presses / (timeMsec / 1000.0)));
    return ret;
}
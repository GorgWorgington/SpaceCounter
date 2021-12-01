#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qwidget.h"
#include "ui_MainWindow.h"
#include <QElapsedTimer>
#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);
    QString timeString(unsigned int n);
    QString rateString(double time, double presses);
    QString totalPressString(int presses);

    bool timerStarted;
    int presses;
    QElapsedTimer *timer;
    QString totalPressLabelText;
    QString rateLabelText;
    QString timeLabelText;

public slots:
    void update();
    void reset();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
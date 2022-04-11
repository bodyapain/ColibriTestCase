#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <declarations.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
public slots:
    void timerProcess();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_checkBox_3_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;

};
//class Timer : public QMainWindow
//{
//    Q_OBJECT

//public:
//    Timer(int hours, int min, int sec);
//    ~Timer();
//public slots:
//    void timerProcess();
//private:
//    Ui::MainWindow *ui;
//    QTimer* timer;

//};
#endif // MAINWINDOW_H

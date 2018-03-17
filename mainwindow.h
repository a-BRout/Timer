#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <string>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTimer *timer;

private:
    Ui::MainWindow *ui;
    int time = 100;
    int koko_aika = 3600000;

public slots:
    void handleButton_start();
    void handleButton_pause();
    void handleButton_stop();
    void handleButton_sound();
    void update();
};

#endif // MAINWINDOW_H

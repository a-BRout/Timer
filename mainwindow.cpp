#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connect(ui->pushButton_Start, SIGNAL(pressed()), this, SLOT(handleButton_start()));
    connect(ui->pushButton_Pause, SIGNAL(pressed()), this, SLOT(handleButton_pause()));
    connect(ui->pushButton_Stop, SIGNAL(pressed()), this, SLOT(handleButton_stop()));
    connect(ui->pushButton_Sound, SIGNAL(pressed()), this, SLOT(handleButton_sound()));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleButton_start()
{
    timer->start(time);
    //ui->label->setText(time);
}

void MainWindow::handleButton_pause()
{
  timer->stop();
}

void MainWindow::handleButton_stop()
{
  timer->stop();
  koko_aika = 3600000;
  int sek = koko_aika/1000;
  int min = koko_aika/(1000*60);
  sek = sek % 60;
  ui->lcdNumber_sek->display(sek);
  ui->lcdNumber_sek_2->display(min);
}

void MainWindow::handleButton_sound()
{
    //play(aani.wav)
}


void MainWindow::update()
{
    koko_aika = koko_aika - 100;
    int sek = koko_aika/1000;
    int min = koko_aika/(1000*60);
    sek = sek % 60;
    ui->lcdNumber_sek->display(sek);
    ui->lcdNumber_sek_2->display(min);

    timer->start(time);
}

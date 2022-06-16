#include "alltasks.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui_auth_reg = new auth_reg;
    ui_tasks = new tasks;
    ui_sta = new sta;
    ui_auth_reg->show();
    connect(ui_auth_reg, &auth_reg::allTasksStart, this, &MainWindow::slot_show);
}

MainWindow::~MainWindow()
{
    delete ui_auth_reg;
    delete ui_tasks;
    delete ui_sta;
    delete ui;
}

void MainWindow::slot_show(QString login){
    ui_tasks -> setLogin(login);
    ui_sta -> setLoginStat(login);
    QString show_login = "Имя пользователя:  " + login;
    ui->label->setText(show_login);
    show();
}

void MainWindow::on_pushBut_t1_clicked()
{
    ui_tasks->set_label();
    ui_tasks->setWindowModality(Qt::ApplicationModal);
    ui_tasks-> set_task1();
    ui_tasks->show();
}


void MainWindow::on_pushBut_t2_clicked()
{
    ui_tasks->set_label();
    ui_tasks->setWindowModality(Qt::ApplicationModal);
    ui_tasks-> set_task2();
    ui_tasks->show();
}


void MainWindow::on_pushBut_t3_clicked()
{
    ui_tasks->set_label();
    ui_tasks->setWindowModality(Qt::ApplicationModal);
    ui_tasks-> set_task3();
    ui_tasks->show();
}


void MainWindow::on_pushBut_t4_clicked()
{
    ui_tasks->set_label();
    ui_tasks->setWindowModality(Qt::ApplicationModal);
    ui_tasks-> set_task4();
    ui_tasks->show();
}

void MainWindow::on_pushBut_stat_clicked()
{
    ui_sta->setWindowModality(Qt::ApplicationModal);
    ui_sta->setStat();
    ui_sta->show();
}

void MainWindow::on_pushButton_exit_clicked()
{
    close();
}

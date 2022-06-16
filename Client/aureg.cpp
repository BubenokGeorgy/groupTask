#include "aureg.h"
#include "ui_auth_reg.h"
#include "QString"
#include "reqs.h"
#include "QMessageBox"

auth_reg::auth_reg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::auth_reg)
{
    ui->setupUi(this);
    ui->lineEdit_email->setVisible(false);
    ui->pushBut_ex->setVisible(false);
    ui->label_status->setText("");
}

auth_reg::~auth_reg()
{
    delete ui;
}

void auth_reg::on_pushBut_reg_clicked()
{
    ui->lineEdit_email->setVisible(true);
    ui->pushBut_ex->setVisible(true);
    ui->pushBut_reg->setVisible(false);
    ui->label_status->setText("");
    ui->lineEd_log->setText("");
    ui->lineEd_pass->setText("");
    ui->lineEdit_email->setText("");
    flag = 1;
}


void auth_reg::on_pushBut_ex_clicked()
{
    ui->lineEdit_email->setVisible(false);
    ui->pushBut_ex->setVisible(false);
    ui->pushBut_reg->setVisible(true);
    ui->label_status->setText("");
    ui->lineEd_log->setText("");
    ui->lineEd_pass->setText("");
    ui->lineEdit_email->setText("");
    flag = 0;
}


void auth_reg::on_pushBut_ok_clicked()
{
    ui->label_status->setText("");
    QString login = ui->lineEd_log->text();
    QString password = ui->lineEd_pass->text();
    if (login == "") {
        ui->label_status->setText("Введите логин");
        ui->label_status->setStyleSheet("color:#ff0000");
    } else if (password == "") {
        ui->label_status->setText("Введите пароль");
        ui->label_status->setStyleSheet("color:#ff0000");
    } else {
        if (flag == 0) {
            QString status = auth(login, password);
            if (status == "true") {
                emit allTasksStart(login);
                hide();
            } else if (status == "false") {
                ui->label_status->setVisible(true);
                ui->label_status->setText("Пароль неверный.");
                ui->label_status->setStyleSheet("color:#ff0000");
            } else if (status == "404") {
                ui->label_status->setVisible(true);
                ui->label_status->setText("Такого пользователя не существует.");
                ui->label_status->setStyleSheet("color:#ff0000");
            }else if (status == "400") {
                ui->label_status->setVisible(true);
                ui->label_status->setText("Неправильный пароль.");
                ui->label_status->setStyleSheet("color:#ff0000");
            }


        } else if (flag == 1) {
            QString email = ui->lineEdit_email->text();
            if (email == "") {
                ui->label_status->setText("Введите емайл");
                ui->label_status->setStyleSheet("color:#ff0000");
            } else {
                QString status = reg(login, password, email);
                if (QString(status) == "true") {
                    ui->label_status->setVisible(true);
                    ui->label_status->setText("Регистрация прошла успешно.");
                    ui->label_status->setStyleSheet("color:#00ff00");
                    ui->lineEdit_email->setVisible(false);
                    ui->pushBut_ex->setVisible(false);
                    ui->pushBut_reg->setVisible(true);
                    ui->lineEd_log->setText("");
                    ui->lineEd_pass->setText("");
                    ui->lineEdit_email->setText("");
                    flag = 0;
                } else if (status == "200") {
                    ui->label_status->setVisible(true);
                    ui->label_status->setText("Такой пользователь уже существует.");
                    ui->label_status->setStyleSheet("color:#ff0000");
                }
            }
        }
    }
}

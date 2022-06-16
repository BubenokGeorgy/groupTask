#include "singletask.h"
#include "ui_tasks.h"
#include "reqs.h"

static int randomBetween(int low, int high)
{
    return (qrand() % ((high + 1) - low) + low);
}

tasks::tasks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tasks)
{
    ui->setupUi(this);
}

tasks::~tasks()
{
    delete ui;
}

void tasks::setLogin(QString login){
    this->login = login;
}

void tasks::set_label(){
    ui->label_status -> setText("");
}

void tasks::set_task_answer(QString n){
    task_answer = n;
}

void tasks::set_task1(){
    QString show_number = "Задание 1";
    task_number = 1;
    ui->task_number->setText(show_number);
    QString input;
    for (int i = 0; i < 16; i++) {
         input+=QString::number(randomBetween(0,1));
     }
    QList<int> numbers;
    QList<int> M1;

    for (int i = 0; i < input.size(); i++) {
        QChar c = input[i];
        int a = c.digitValue();
        numbers.push_back(a);
        if (a != 0) {
            M1.push_back(i);
        }
    }
    QString sM1;
    foreach(int n, M1) {
        sM1 += QString::number(n) + " ";
    }
    set_task_answer(sM1.trimmed());
    QString task = "Заданную функцию f("+input+") представить: множеством M1 десятичных эквивалентов двоичных наборов через пробел, на которых f принимает значение 1";
    ui->textBrw_task->setText(task);
}

void tasks::set_task2(){
    QString show_number = "Задание 2";
    task_number = 2;
    ui->task_number->setText(show_number);
    int a = randomBetween(0,100);
    int b = randomBetween(0,100);
    QString str;
    set_task_answer(str.setNum(a+b));
    QString task = "У Андрея было "+QString::number(a)+" яблока, а у Вани "+QString::number(b)+". Сколько у них было всего яблок?";
    ui->textBrw_task->setText(task);
}

void tasks::set_task3(){
    QString show_number = "Задание 3";
    task_number = 3;
    ui->task_number->setText(show_number);
    int a = randomBetween(0,100);
    int b = randomBetween(0,100);
    QString str;
    set_task_answer(str.setNum(a+b));
    QString task = "У Кости было "+QString::number(a)+" яблока, а у Вани "+QString::number(b)+". Сколько у них было всего яблок?";
    ui->textBrw_task->setText(task);
}

void tasks::set_task4(){
    QString show_number = "Задание 4";
    task_number = 4;
    ui->task_number->setText(show_number);
    int a = randomBetween(0,100);
    int b = randomBetween(0,100);
    QString str;
    set_task_answer(str.setNum(a+b));
    QString task = "У Александра было "+QString::number(a)+" яблока, а у Вани "+QString::number(b)+". Сколько у них было всего яблок?";
    ui->textBrw_task->setText(task);
}


void tasks::on_pushBut_check_clicked()
{
    QString output = "Ответ неверный";
    QString answer = ui->lineEdit_ans->text();
    if (answer == "") {
        output = "Введите ответ";
    } else if (answer == (task_answer)){
             output = "Ответ верный";
             add(login, QString::number(task_number));
             if (task_number==1){
                set_task1();
            } else if (task_number==2){
            set_task2();
              }else if (task_number==3){
            set_task3();
             }else if (task_number==4){
            set_task4();
        }
    }
    ui->lineEdit_ans -> setText("");
    ui->label_status->setText(output);
}


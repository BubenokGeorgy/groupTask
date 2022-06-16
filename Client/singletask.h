#ifndef SINGLETASK_H
#define SINGLETASK_H

#include <QWidget>

namespace Ui {
class tasks;
}

class tasks : public QWidget
{
    Q_OBJECT

public:
    explicit tasks(QWidget *parent = nullptr);
    ~tasks();
    void set_task1();
    void set_task_answer(QString n);
    void set_label();
    void setLogin(QString login);
    void set_task2();
    void set_task3();
    void set_task4();
    void clear();
private slots:
    void on_pushBut_check_clicked();

private:
    Ui::tasks *ui;
    int task_number;
    QString task_answer;
    QString login;
};

#endif

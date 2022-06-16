#ifndef AUREG_H
#define AUREG_H

#include <QWidget>

namespace Ui {
class auth_reg;
}

class auth_reg : public QWidget
{
    Q_OBJECT

public:
    explicit auth_reg(QWidget *parent = nullptr);
    ~auth_reg();

private slots:
    void on_pushBut_reg_clicked();

    void on_pushBut_ex_clicked();

    void on_pushBut_ok_clicked();

signals:
    void allTasksStart (QString login);

private:
    Ui::auth_reg *ui;

private:
    int flag = 0;
};

#endif

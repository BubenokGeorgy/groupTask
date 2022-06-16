#ifndef ALLTASKS_H
#define ALLTASKS_H

#include "aureg.h"
#include "singletask.h"
#include "sta.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    auth_reg *ui_auth_reg;
    tasks *ui_tasks;
    sta *ui_sta;

private slots:
    void slot_show(QString login);
    void on_pushBut_t1_clicked();
    void on_pushBut_t2_clicked();
    void on_pushBut_t3_clicked();
    void on_pushBut_t4_clicked();
    void on_pushBut_stat_clicked();
    void on_pushButton_exit_clicked();
};
#endif

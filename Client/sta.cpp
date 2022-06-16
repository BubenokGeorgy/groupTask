#include "sta.h"
#include "ui_sta.h"
#include "reqs.h"

sta::sta(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sta)
{
    ui->setupUi(this);
}

sta::~sta()
{
    delete ui;
}

void sta::setLoginStat(QString login){
    this->login = login;
}

void sta::setStat(){
    QString res = get(login);
    QStringList parameters = res.split(QLatin1Char(' '));
    ui->textBrowser_5 -> setText(parameters.at(0));
    ui->textBrowser_6 -> setText(parameters.at(1));
    ui->textBrowser_7 -> setText(parameters.at(2));
    ui->textBrowser_8 -> setText(parameters.at(3));
}

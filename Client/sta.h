#ifndef STA_H
#define STA_H

#include <QWidget>

namespace Ui {
class sta;
}

class sta : public QWidget
{
    Q_OBJECT

public:
    explicit sta(QWidget *parent = nullptr);
    ~sta();
    void setStat();
    void sta::setLoginStat(QString login);

private:
    Ui::sta *ui;
    QString login;
};

#endif

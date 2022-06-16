#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <QCoreApplication>

class Expression
{
public:
    Expression(QString value);
    QString getValue();
private:
    QString value;

};

#endif // EXPRESSION_H

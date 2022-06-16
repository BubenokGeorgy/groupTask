#include "expression.h"

Expression::Expression(QString value)
{
    this->value = value;
}

QString Expression::getValue()
{
    return this->value;
}

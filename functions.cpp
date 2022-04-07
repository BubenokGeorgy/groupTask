/*!
 * \file
 * \brief Файл с имплементацией функций, заданных в functions.h
 */

#include "functions.h"
#include "DataBase.h"

QByteArray parse (QString command, qintptr socketDescriptor) {
        QStringList parameters = command.split(QLatin1Char(' '));
        QString function = parameters.at(0);
        parameters.pop_front();

        if (function == "auth") {
            if (parameters.length() == 2) return auth(parameters.at(0), parameters.at(1), socketDescriptor);
            else return "wrong number of parameters\n";
        }
        else if (function == "reg") {
            if (parameters.length() == 3) return reg(parameters.at(0), parameters.at(1), parameters.at(2), socketDescriptor);
            else return "wrong number of parameters\n";
        }
        else return "Uncknown command\n";
}


QByteArray auth(QString login, QString password, qintptr socketDescriptor)
{
    QByteArray result = "";
    DataBase::getInstance();
    result.append(DataBase::dataCheck(login, password).toUtf8());
    result.append("\n");
    return result;
}

QByteArray reg(QString login, QString password, QString email, qintptr socketDescriptor)
{
    QByteArray result = "";
    DataBase::getInstance();
    result.append(DataBase::addData(login, password, email).toUtf8());
    result.append("\n");
    return result;
}

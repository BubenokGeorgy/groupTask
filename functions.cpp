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
            else return "wrong number of parameters";
        }
        else if (function == "reg") {
            if (parameters.length() == 3) return reg(parameters.at(0), parameters.at(1), parameters.at(2), socketDescriptor);
            else return "wrong number of parameters";
        }
        else if (function == "add") {
            if (parameters.length() == 2) return add(parameters.at(0),parameters.at(1), socketDescriptor);
            else return "wrong number of parameters";
        }
        else if (function == "get") {
            if (parameters.length() == 1) return getStat(parameters.at(0), socketDescriptor);
            else return "wrong number of parameters";
        }
        else return "Unknown command";
}


QByteArray add(QString login, QString num, qintptr socketDescriptor){
    QByteArray result = "";
    DataBase::getInstance();
    result.append(DataBase::addTask(login, num).toUtf8());
    return result;
}

QByteArray getStat(QString login, qintptr socketDescriptor){
    QByteArray result = "";
    DataBase::getInstance();
    result.append(DataBase::get(login).toUtf8());
    return result;
}

QByteArray auth(QString login, QString password, qintptr socketDescriptor)
{
    QByteArray result = "";
    DataBase::getInstance();
    result.append(DataBase::dataCheck(login, password).toUtf8());
    return result;
}

QByteArray reg(QString login, QString password, QString email, qintptr socketDescriptor)
{
    QByteArray result = "";
    DataBase::getInstance();
    result.append(DataBase::addData(login, password, email).toUtf8());
    return result;
}

#include "reqs.h"

QString auth(QString login, QString password){
    QString result = "";
    result = "auth " + login + " " + password;
    return ConnectServer::ToServer(result);
}

QString add(QString login, QString num){
    QString result = "";
    result = "add " + login + " " + num;
    return ConnectServer::ToServer(result);
}

QString get(QString login){
    QString result = "";
    result = "get " + login;
    return ConnectServer::ToServer(result);
}

QString reg(QString login, QString password, QString email){
    QString result = "";
    result = "reg " + login + " " + password + " " + email;
    return ConnectServer::ToServer(result);
}


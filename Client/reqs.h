#ifndef REQS_H
#define REQS_H
#include "QString"
#include "QDebug"
#include "ConnectServer.h"

QString auth(QString login, QString password);
QString reg(QString login, QString password, QString email);
QString add(QString login, QString num);
QString get(QString login);

#endif

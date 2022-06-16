#include "alltasks.h"
#include "aureg.h"
#include "singletask.h"
#include "sta.h"
#include "ConnectServer.h"
#include <QApplication>
#include <QMessageBox>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ConnectServer::getInstance();
    MainWindow w;
    return a.exec();
}

ConnectServer * ConnectServer::p_instance = nullptr;
ConnectServerDestroyer ConnectServer::destroyer;
ConnectToServer * ConnectServer::Server = nullptr;

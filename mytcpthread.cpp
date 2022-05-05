/*!
 * \file
 * \brief Файл, содержащий имплементацию методов класса MyTcpThread
 */

#include "mytcpthread.h"

MyTcpThread::~MyTcpThread() {
    requestInterruption();
    wait();
}

MyTcpThread::MyTcpThread(qintptr threadDesc, QObject *parent) : QThread{parent} {
    this->socketDescriptor = threadDesc;
}

void MyTcpThread::run() {
    socket = new QTcpSocket();
    socket->setSocketDescriptor(this->socketDescriptor);

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    exec();
}

void MyTcpThread::readyRead() {
    if (socket->bytesAvailable()>0) {
        QByteArray command = socket->readAll();
        if (command.length() > 0) {
            command.remove(command.size()-2,2);
            socket->write(parse(command, socket->socketDescriptor()));
        }
    }
}

void MyTcpThread::disconnected() {
    socket->deleteLater();
    exit(0);
}

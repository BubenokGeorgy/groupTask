/*!
 * \file
 * \brief Заголовочный файл с описанием класса MyTcpThread
 */

#ifndef MYTCPTHREAD_H
#define MYTCPTHREAD_H

#include "functions.h"

#include <QThread>
#include <QObject>
#include <QTcpSocket>
#include <QDebug>

/*!
 * \brief MyTcpThread - класс, описывающий работу с потоками, в которых происходит взаимодействие с клиентами
 * \details Класс MyTcpThread используется для создания инстанций QThread для каждого подключаемого к серверу клиента, то есть выделяет по потоку для работы с с каждым клиентом
 */
class MyTcpThread : public QThread
{
        Q_OBJECT
public:
    /*!
     * \brief MyTcpThread - конструктор класса MyTcpThread
     * \details Создает объект MyTcpThread и сохраняет автогенерируемый дескриптор
     * \param [in] threadDesc - автогенерируемый дескриптор, полученный от incomingConnection()
     * \param [in] parent - родительский объект MyTcpServer
     */
    explicit MyTcpThread(qintptr threadDesc, QObject *parent = nullptr);
    ~MyTcpThread();
    public slots:
    /*!
         * \brief readyRead - слот, связанный с нативным сигналом readyRead
         * \details Вызывается при сигнале readyRead (приеме сообщения от клиента), считывает данные, введённые клиентом и передает их в parse(), после чего отправяется ответ сервера клиенту
         * \warning Работает некорректно с telnet клиентом PuTTY
         */
        void readyRead();
        /*!
         * \brief disconnected - слот, связанный с нативным сигналом disconnected
         * \details Вызывается при сигнале disconnected (разрыве соединения между клиентом и сервером). Уничтожает сокет клиента и завершает event loop
         */
        void disconnected();

protected:
        /*!
        * \brief run - виртуальная функция класса QThread
        * \details Вызывается после вызова метода start() объекта класса MyTcpThread. Создает новый поток с event loop и сокет клиента. Назначает сокету дескриптор socketDescriptor (class member) и создает подключение между сигналами клиента и соответствующими слотами сервера
        */
       void run();
private:
       QTcpSocket *socket;
       qintptr socketDescriptor;

};

#endif

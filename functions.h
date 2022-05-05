 /*!
 * \file
 * \brief Заголовочный файл, определяющий функции сервера для взаимодействия с клиентом
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QStringList>
#include <QString>


/*!
 * \brief parse - функция, выполняющая парсинг сообщений клиента для дальней передачи параметров функциям
 * \param [in] command - сообщение клиента
 * \param [in] socketDescriptor - дескриптор сокета клиента, от которого было получено сообщение
 * \return Возвращает результат работы функции, вызываемой клиентом
 */
QByteArray parse(QString data_from_client, qintptr socketDescriptor);

/*!
 * \brief auth - функция, коотрая проверчяет существование аккаунта и если он есть, то проводится аутентификация клиента
 * \param [in] login - логин, полученный из сообщения пользователя
 * \param [in] password - пароль, полученный из сообщения пользователя
 * \param [in] socketDescriptor - дескриптор сокета клиента, совершающего аутентификацию
 * \return Возвращает сообщение с результатом аутентификации пользователя
 */
QByteArray auth(QString login, QString password, qintptr socketDescriptor);

/*!
 * \brief reg - функция, которая проверяет существование аккаунта клиента и если его нет,то проводится регистрация клиента
 * \param [in] login - логин, полученный из сообщения пользователя
 * \param [in] password - создаваемый пароль, полученный из сообщения пользователя
 * \param [in] email - электронная почта, полученная из сообщения пользователя
 * \param [in] socketDescriptor - дескриптор сокета клиента, совершающего регистрацию
 * \return Возвращает сообщение с результатом регистрации пользователя
 */
QByteArray reg(QString login, QString password, QString email, qintptr socketDescriptor);

#endif

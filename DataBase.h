/*!
* \file
* \brief Заголовочный файл, определяющий функции для работа с базой данных
*/

#ifndef DATABASE_H
#define DATABASE_H
#pragma once

#include <QString>
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

class DataBase;

/*!
 * \brief DataBaseDestroyer - класс, нужный для реализации удаления текущей бд
 * \details Класс DataBaseDestroyer используется для того, чтобы удалить ссылку на текущую базу данных
 */
class DataBaseDestroyer
{
    private:
        DataBase * p_instance;
    public:
        ~DataBaseDestroyer() { delete p_instance;}

        void initialize(DataBase * p)
        {
            p_instance = p;
        }
};

/*!
 * \brief DataBase - класс, описывающий взаимодействией с базой даннах
 * \details Класс DataBase используется для того, чтобы создать базу данных, открыть его, записать в неё данные и получить требуемые результаты
 */
class DataBase
{
    private:
        static DataBase * p_instance;
        static DataBaseDestroyer destroyer;
        static QSqlDatabase db;
    public:
        /*!
         * \brief getInstance - функция, вовзращающая ссылку на текущую бд
         * \param [in] email - почта клиента
         * \return Возвращает ссылку на текущую или, если такая отсутсвует, новую бд
         */
        static DataBase* getInstance(){
            if (!p_instance)
            {
                p_instance = new DataBase();

                p_instance->db = QSqlDatabase::addDatabase("QSQLITE");
                p_instance->db.setDatabaseName("db5.db");

                if (!p_instance->db.open())
                   { qDebug() << p_instance->db.lastError().text();}
                else {
                    QSqlQuery query;
                    query.exec("create table User "
                              "(login varchar(40),"
                               "password varchar(40), "
                              "email varchar(40))"
                              );
                }


                destroyer.initialize(p_instance);
            }
            return p_instance;
        }

        /*!
         * \brief addData - функция, записывающая данные в бд
         * \param [in] login - логин клиента
         * \param [in] password - пароль клиента
         * \param [in] email - почта клиента
         * \return Возвращает результат записи
         */
        static QString addData(QString login, QString password, QString email) {
            if (DataBase::dataCheck(login, password) != "NoSuchUser") return "SuchUserAlreadyExists";
            else {
                QSqlQuery query(p_instance->db);
                query.prepare("INSERT INTO User(login, password, email)"
                                "VALUES (:login, :password, :email)");
                query.bindValue(":login", login);
                query.bindValue(":password", password);
                query.bindValue(":email", email);
                query.exec();
            return "True";
            }
        };

        /*!
         * \brief dataCheck - функция, проверяющая наличие данных в бд
         * \param [in] login - логин клиента
         * \param [in] password - пароль клиента
         * \return Возвращает результат проверки
         */
        static QString dataCheck(QString login, QString password) {
            QSqlQuery query(p_instance->db);
            query.prepare("SELECT * FROM User where login = :login");
            query.bindValue(":login", login);
            query.exec();
            QSqlRecord rec = query.record();
            int PasswordIndex = rec.indexOf("password");
            query.prepare("SELECT * FROM User");
            query.exec();
            QSqlRecord rec2 = query.record();
            qDebug() << rec2;
            if (!query.next()) return "NoSuchUser";
            else {
                QString TruePassword = query.value(PasswordIndex).toString();
                if (TruePassword == password) return "True";
                else return "False";
            }
        }


        /*!
         * \brief closeDB - функция, закрываюшая базу данных
         */
        static void closeDB()
        {
            p_instance->db.close();
        }

};


DataBase * DataBase::p_instance = nullptr;
DataBaseDestroyer DataBase::destroyer;
QSqlDatabase DataBase::db;

#endif

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
        DataBase(){
            db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName("db.db");
            if (db.open())
               {
                QSqlQuery query;
                                   query.exec("create table User "
                                             "(login varchar(40),"
                                              "password varchar(40), "
                                             "email varchar(40), "
                                              "task1 integer,"
                                              "task2 integer,"
                                              "task3 integer,"
                                              "task4 integer)"
                                             );
            }

        }
        ~DataBase(){
            db.close();
        }
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
            if (DataBase::dataCheck(login, password) != "404") return "200";
            else {
                QSqlQuery query(db);
                query.prepare("INSERT INTO User(login, password, email)"
                                "VALUES (:login, :password, :email)");
                query.bindValue(":login", login);
                query.bindValue(":password", password);
                query.bindValue(":email", email);
                query.exec();
            return "true";
            }
        };

        static QString get(QString login) {
            QSqlQuery query(db);
            query.prepare("SELECT * FROM User where login = :login");
            query.bindValue(":login", login);
            query.exec();
            QSqlRecord rec = query.record();
            int taskIndex = rec.indexOf("task1");
            query.next();
            QString res = QString::number(query.value(taskIndex).toInt())+" ";
            res.append(QString::number(query.value(taskIndex+1).toInt())+" ");
            res.append(QString::number(query.value(taskIndex+2).toInt())+" ");
            res.append(QString::number(query.value(taskIndex+3).toInt()));
            qDebug() << res;
            return res;
        }

        static QString addTask(QString login, QString num) {

             QSqlQuery query(db);
             query.prepare("SELECT * FROM User where login = :login");
             query.bindValue(":login", login);
             query.exec();
             QSqlRecord rec = query.record();
             int taskIndex = rec.indexOf("task"+num);
             query.next();
             int taskNum = query.value(taskIndex).toInt();
             query.prepare("UPDATE User SET task"+num+"=:num WHERE login = :login");
             query.bindValue(":login", login);
             query.bindValue(":num", taskNum+1);
             query.exec();
            return "true";
        };

        /*!
         * \brief dataCheck - функция, проверяющая наличие данных в бд
         * \param [in] login - логин клиента
         * \param [in] password - пароль клиента
         * \return Возвращает результат проверки
         */
        static QString dataCheck(QString login, QString password) {
            QSqlQuery query(db);
            query.prepare("SELECT * FROM User where login = :login");
            query.bindValue(":login", login);
            query.exec();
            QSqlRecord rec = query.record();
            int PasswordIndex = rec.indexOf("password");
            if (!query.next()) return "404";
            else {
                QString TruePassword = query.value(PasswordIndex).toString();
                if (TruePassword == password) return "true";
                else return "400";
            }
        }


        /*!
         * \brief closeDB - функция, закрываюшая базу данных
         */


};


DataBase * DataBase::p_instance = nullptr;
DataBaseDestroyer DataBase::destroyer;
QSqlDatabase DataBase::db;

#endif

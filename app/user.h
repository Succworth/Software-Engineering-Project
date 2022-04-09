#ifndef USER_H
#define USER_H
#include <QMainWindow>
#include <QtSql>

class User
{
public:
    User(QString id, QString name);
    //Will add more data here
    QString id;
    QString name;

};

#endif // USER_H

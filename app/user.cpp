#include "user.h"


User::User(QString id, QString name)
{
    /*QSqlQuery query("SELECT * FROM CRACKINGASL WHERE STUDENT_ID ='"+id+"' AND STUDENT_NAME ='"+name+"'");
    if(query.first()){
        id = query.value(0).toString();
        name = query.value(1).toString();
        //put rest of info grab here
    }*/
    this->id = id;
    this->name = name;
}

#include "crackingasl.h"
#include "ui_crackingasl.h"
#include <QVariant>
#include <QSqlQuery>
CrackingASL::CrackingASL(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CrackingASL)
{

    ui->setupUi(this);

    //start of db connection code
    db = QSqlDatabase::addDatabase("QSQLITE");
    QDir exeDir(QCoreApplication::applicationDirPath());
    qDebug() <<  exeDir.path()+"/db/data.db";
    db.setDatabaseName(exeDir.path()+"/db/data.db");
    if(!db.open()){
        //throw error or warning or debug message
         qWarning() << "db connection error:" << db.lastError();
    } else {
        //connection works
    }
    //end of db connection code
}

CrackingASL::~CrackingASL()
{
    delete ui;
}


void CrackingASL::login(){
    QString id = ui->lineEdit_2->text();
    QString name = ui->lineEdit->text();
    qDebug() << "Before checks";
    /* Verifying input to prevent possible SQL injection attack
     */
    bool valid = true;

    for(unsigned int i = 0; i < id.size(); i++){
        if(!(id[i].isDigit())){
            valid = false;
            break;
        }
    }

    for(unsigned int i = 0; i < name.size(); i++){
        if(!(name[i].isLetter())){
            valid = false;
            break;
        }
    }
    qDebug() << "After checks";

    if(valid){
        qDebug() << "Valid test";
    }

    if(valid){
        qDebug() << "Before query";

        QSqlQuery query("SELECT * FROM CRACKINGASL WHERE STUDENT_ID ='"+id+"' AND STUDENT_NAME ='"+name+"'");

        qDebug() << "Valid input";

        if(query.first()){
            hide();
            qDebug() << "Valid input 1";
            mainMenu = new MainMenu(this);
            qDebug() << "Valid input 2";
            mainMenu->show();
            qDebug() << "Valid input 3";
            mainMenu->setUserText(query.value(0).toString(), query.value(1).toString());
            qDebug() << "Valid input 4";
            //ui->label_3->setText(query.value(1).toString());
        }else{
            ui->label_3->setText("Incorrect Login Information");
        }
    }else{
        ui->label_3->setText("Incorrect Login Information");
    }
}

void CrackingASL::on_pushButton_clicked()
{
   login();

}

//Allows user to click enter after id to login
void CrackingASL::on_lineEdit_2_returnPressed()
{
    login();
}

void CrackingASL::on_pushButton_2_clicked()
{
    createAccount();
}

void CrackingASL::createAccount()
{
    QString id = ui->lineEdit_2->text();
    QString name = ui->lineEdit->text();
    qDebug() << "Before checks";
    /* Verifying input to prevent possible SQL injection attack
     */
    bool valid = true;

    for(unsigned int i = 0; i < id.size(); i++){
        if(!(id[i].isDigit())){
            valid = false;
            break;
        }
    }

    for(unsigned int i = 0; i < name.size(); i++){
        if(!(name[i].isLetter())){
            valid = false;
            break;
        }
    }
    qDebug() << "After checks";

    if(valid){
        qDebug() << "Valid test";
    }

    if(valid){
        QSqlQuery query("SELECT * FROM CRACKINGASL WHERE STUDENT_ID ='"+id+"'");
        if(query.first()){
            ui->label_3->setText("User ID already exist");
        }
        else{
        db.open();
        QSqlQuery query1("INSERT INTO CRACKINGASL(STUDENT_ID,STUDENT_NAME) "
                          "VALUES ('"+id+"', '"+name+"') ");
       // query1.prepare("INSERT INTO CRACKINGASL(STUDENT_ID,STUDENT_NAME) "
       //                "VALUES (?,?) ");
       //               // "VALUES ('"+id+"', '"+name+"') ");
       // query1.addBindValue(id);
       // query1.addBindValue(name);
        query1.exec();
       // if(query1.exec()){
        ui->label_3->setText("Account Created Successfully");
       //     }
       //     else{
       //     ui->label_3->setText("failed");
       //     db.close();
       // }
        }
    }
    //ui->label_3->setText("Creating button works");
}

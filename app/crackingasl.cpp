#include "crackingasl.h"
#include "ui_crackingasl.h"

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
    QSqlQuery query("SELECT * FROM CRACKINGASL WHERE STUDENT_ID ='"+id+"' AND STUDENT_NAME ='"+name+"'");

    if(query.first()){
        hide();
        mainMenu = new MainMenu(this);
        mainMenu->show();
        mainMenu->setUserText(query.value(0).toString(), query.value(1).toString());
        //ui->label_3->setText(query.value(1).toString());
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


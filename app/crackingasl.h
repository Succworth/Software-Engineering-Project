#ifndef CRACKINGASL_H
#define CRACKINGASL_H

#include <QMainWindow>
#include <QtSql>
#include <QVariant>
#include <QSqlQuery>
#include <QSqlDatabase>
#include "mainmenu.h"
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CrackingASL; }
QT_END_NAMESPACE

class CrackingASL : public QMainWindow
{
    Q_OBJECT

public:
    CrackingASL(QWidget *parent = nullptr);
    ~CrackingASL();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_lineEdit_2_returnPressed();

private:
    Ui::CrackingASL *ui;
    QSqlDatabase db;
    MainMenu *mainMenu;
    User *user;
    void login();
    void createAccount();
};
#endif // CRACKINGASL_H

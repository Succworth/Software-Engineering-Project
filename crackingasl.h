#ifndef CRACKINGASL_H
#define CRACKINGASL_H

#include <QMainWindow>
#include <QtSql>
#include "mainmenu.h"

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

private:
    Ui::CrackingASL *ui;
    QSqlDatabase db;
    MainMenu *mainMenu;

};
#endif // CRACKINGASL_H

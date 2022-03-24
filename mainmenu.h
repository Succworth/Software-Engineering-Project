#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();
    void setUserText(QString name, QString id);
    void init_menu();

private:
    Ui::MainMenu *ui;

};

#endif // MAINMENU_H

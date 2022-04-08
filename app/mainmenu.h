#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include "gamewindow.h"
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
    void open_lesson();
    void open_benchmark();
private:
    Ui::MainMenu *ui;
    GameWindow* gameWindow;
};

#endif // MAINMENU_H

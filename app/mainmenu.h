#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include "gamewindow.h"
#include "benchmarkwindow.h"

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
    void open_lesson(int i);
    void open_benchmark(int i);
private:
    Ui::MainMenu *ui;
    GameWindow* gameWindow;
    BenchmarkWindow* benchmarkWindow;
};

#endif // MAINMENU_H

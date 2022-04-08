#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>

class MainMenu;

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr, bool isBenchmark = false);
    ~GameWindow();

private:
    Ui::GameWindow *ui;
    bool is_benchmark;
    void open_mainmenu();
};

#endif // GAMEWINDOW_H

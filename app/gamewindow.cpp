#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "mainmenu.h"

GameWindow::GameWindow(QWidget *parent, bool isBenchmark) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    is_benchmark = isBenchmark;

    QObject::connect(ui->pushButton, &QPushButton::clicked, this, &GameWindow::open_mainmenu);
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::open_mainmenu(){
    hide();
    //do saving and destruction
    MainMenu* mainmenu = new MainMenu(this);
    mainmenu->show();
}

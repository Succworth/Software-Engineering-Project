#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include <random>
#include "answerkey.h"
#include "user.h"

class MainMenu;

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr, int i = 1, User *user = nullptr);
    ~GameWindow();

private slots:
    void on_Next_clicked();

    void on_Choice_A_clicked();

    void on_Choice_B_clicked();

    void on_Choice_C_clicked();

    void on_Choice_D_clicked();

    void on_Retry_clicked();
private:
    Ui::GameWindow *ui;
    AnswerKey *a;
    QString currQuestion;
    User *user;
    int lessonNumber;
    bool clicked = false;
    void open_mainmenu();
    void displayQuestion();
    void resetButtons();
    QVector<QString> randomize(QVector<QString> &choices);
};

#endif // GAMEWINDOW_H

#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include <random>
#include "answerkey.h"

class MainMenu;

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr, bool isBenchmark = false, int i = 1);
    ~GameWindow();

private slots:
    void on_Next_clicked();

    void on_Choice_A_clicked();

    void on_Choice_B_clicked();

    void on_Choice_C_clicked();

    void on_Choice_D_clicked();

private:
    Ui::GameWindow *ui;
    AnswerKey *a;
    QString currQuestion;
    int lessonNumber;
    bool is_benchmark;
    void open_mainmenu();
    void displayQuestion();
    void resetButtons();
    QVector<QString> randomize(QVector<QString> &choices);
};

#endif // GAMEWINDOW_H

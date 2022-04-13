#ifndef BENCHMARKWINDOW_H
#define BENCHMARKWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include <random>
#include "answerkey.h"

namespace Ui {
class BenchmarkWindow;
}

class BenchmarkWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BenchmarkWindow(QWidget *parent = nullptr, int i = 1);
    ~BenchmarkWindow();
private slots:
    void on_Next_clicked();

    void on_Choice_A_clicked();

    void on_Choice_B_clicked();

    void on_Choice_C_clicked();

    void on_Choice_D_clicked();

    void on_Retry_clicked();

private:
    Ui::BenchmarkWindow *ui;
    AnswerKey *a;
    QString currQuestion;
    QVector<QString> questionSet;
    int questionNo;
    int lessonNumber;
    bool clicked = false;
    void open_mainmenu();
    void displayQuestion();
    void resetButtons();
    QVector<QString> randomize(QVector<QString> &choices);
};

#endif // BENCHMARKWINDOW_H

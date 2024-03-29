#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "mainmenu.h"

GameWindow::GameWindow(QWidget *parent, int i, User *user) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    lessonNumber = i;
    this->user = user;
    a = new AnswerKey(i);
    displayQuestion();


    QObject::connect(ui->pushButton, &QPushButton::clicked, this, &GameWindow::open_mainmenu);
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::open_mainmenu(){
    hide();
    //do saving and destruction
    MainMenu* mainmenu = new MainMenu(this, user);
    mainmenu->show();
}

QVector<QString> GameWindow::randomize(QVector<QString> &choices) {
    QVector<QString> temp;
    while (temp.size() < choices.size()) {
        QString test = choices[rand() % 4];
        if (temp.contains(test)) {
            continue;
        }
        else {
            temp.push_back(test);
        }
    }

    return temp;
}

//Displays gif + choices
void GameWindow::displayQuestion() {
    ui->Next->hide();

    currQuestion = a->getQuestion();
    QVector<QString> choices = a->getChoices(currQuestion, 3);
    choices = randomize(choices);

    ui->Choice_A->setText(choices[0]);
    ui->Choice_B->setText(choices[1]);
    ui->Choice_C->setText(choices[2]);
    ui->Choice_D->setText(choices[3]);

    QString path = ":/Assets/Common Words and Phrases " + QString::number(lessonNumber) + "/";
    if(lessonNumber == 0) { path = ":/Assets/Alphabet/"; }
    QMovie *movie = new QMovie(path + currQuestion + ".gif");
    ui->label->setMovie(movie);
    ui->label->setScaledContents(true);
    movie->start();
    ui->Next->hide();
}

//Reset button colors
void GameWindow::resetButtons() {
    ui->Choice_A->setStyleSheet("* { border-color: #051a39 }");
    ui->Choice_A->setEnabled(true);
    ui->Choice_A->update();

    ui->Choice_B->setStyleSheet("* { border-color: #051a39 }");
    ui->Choice_B->setEnabled(true);
    ui->Choice_B->update();

    ui->Choice_C->setStyleSheet("* { border-color: #051a39 }");
    ui->Choice_C->setEnabled(true);
    ui->Choice_C->update();

    ui->Choice_D->setStyleSheet("* { border-color: #051a39 }");
    ui->Choice_D->setEnabled(true);
    ui->Choice_D->update();

}

//Flow of questions
void GameWindow::on_Next_clicked()
{
    resetButtons();
    displayQuestion();
}


void GameWindow::on_Choice_A_clicked()
{
    QString text = ui->Choice_A->text();
    if (text.compare(currQuestion) == 0) {
        ui->Choice_A->setStyleSheet("background-color: #607cff;color: #ffffff;border-style: solid;border-width: 3px;border-radius: 3px;border-color: #00ff00;padding: 5px;");
        ui->Choice_B->setEnabled(false);
        ui->Choice_B->update();
        ui->Choice_C->setEnabled(false);
        ui->Choice_C->update();
        ui->Choice_D->setEnabled(false);
        ui->Choice_D->update();
        ui->Choice_A->update();
        ui->Next->show();
    }
    else {
        ui->Choice_A->setStyleSheet("* { border-color: #ff0000 }");
        ui->Choice_A->setEnabled(false);
        ui->Choice_A->update();
    }
}


void GameWindow::on_Choice_B_clicked()
{
    //resetButtons();
    QString text = ui->Choice_B->text();
    if (text.compare(currQuestion) == 0) {
        ui->Choice_B->setStyleSheet("background-color: #607cff;color: #ffffff;border-style: solid;border-width: 3px;border-radius: 3px;border-color: #00ff00;padding: 5px;");
        ui->Choice_A->setEnabled(false);
        ui->Choice_C->setEnabled(false);
        ui->Choice_D->setEnabled(false);;
        ui->Choice_B->update();
        ui->Next->show();
    }
    else {
        ui->Choice_B->setStyleSheet("* { border-color: #ff0000 }");
        ui->Choice_B->setEnabled(false);
        ui->Choice_B->update();
    }
}


void GameWindow::on_Choice_C_clicked()
{
    QString text = ui->Choice_C->text();
    if (text.compare(currQuestion) == 0) {
        ui->Choice_C->setStyleSheet("background-color: #607cff;color: #ffffff;border-style: solid;border-width: 3px;border-radius: 3px;border-color: #00ff00;padding: 5px;");
        ui->Choice_A->setEnabled(false);
        ui->Choice_B->setEnabled(false);
        ui->Choice_D->setEnabled(false);
        ui->Choice_C->update();
        ui->Next->show();
    }
    else {
        ui->Choice_C->setStyleSheet("* { border-color: #ff0000 }");
        ui->Choice_C->setEnabled(false);
        ui->Choice_C->update();
    }
}


void GameWindow::on_Choice_D_clicked()
{
    QString text = ui->Choice_D->text();
    if (text.compare(currQuestion) == 0) {
        ui->Choice_D->setStyleSheet("background-color: #607cff;color: #ffffff;border-style: solid;border-width: 3px;border-radius: 3px;border-color: #00ff00;padding: 5px;");
        ui->Choice_A->setEnabled(false);
        ui->Choice_B->setEnabled(false);
        ui->Choice_C->setEnabled(false);
        ui->Choice_D->update();
        ui->Next->show();
    }
    else {
        ui->Choice_D->setStyleSheet("* { border-color: #ff0000 }");
        ui->Choice_D->setEnabled(false);
        ui->Choice_D->update();
    }
}


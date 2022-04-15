#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "mainmenu.h"

// Add alphabet

GameWindow::GameWindow(QWidget *parent, int i) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    lessonNumber = i;

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
    MainMenu* mainmenu = new MainMenu(this);
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

    QDir exeDir(QCoreApplication::applicationDirPath());
    qDebug() <<  exeDir.path()+"/Assets.qrc";
    QResource::registerResource(exeDir.path()+"/Assets.qrc");
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
    QPalette pal = ui->Choice_A->palette();
    pal.setColor(QPalette::Button, QColor(QColorConstants::White));
    ui->Choice_A->setAutoFillBackground(true);
    ui->Choice_A->setPalette(pal);
    ui->Choice_A->update();

    pal = ui->Choice_B->palette();
    pal.setColor(QPalette::Button, QColor(QColorConstants::White));
    ui->Choice_B->setAutoFillBackground(true);
    ui->Choice_B->setPalette(pal);
    ui->Choice_B->update();

    pal = ui->Choice_C->palette();
    pal.setColor(QPalette::Button, QColor(QColorConstants::White));
    ui->Choice_C->setAutoFillBackground(true);
    ui->Choice_C->setPalette(pal);
    ui->Choice_C->update();

    pal = ui->Choice_D->palette();
    pal.setColor(QPalette::Button, QColor(QColorConstants::White));
    ui->Choice_D->setAutoFillBackground(true);
    ui->Choice_D->setPalette(pal);
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
    resetButtons();
    QString text = ui->Choice_A->text();
    if (text.compare(currQuestion) == 0) {
       QPalette pal = ui->Choice_A->palette();
       pal.setColor(QPalette::Button, QColor(QColorConstants::Green));
       ui->Choice_A->setAutoFillBackground(true);
       ui->Choice_A->setPalette(pal);
       ui->Choice_A->update();
       ui->Next->show();
    }
    else {
        QPalette pal = ui->Choice_A->palette();
        pal.setColor(QPalette::Button, QColor(QColorConstants::Red));
        ui->Choice_A->setAutoFillBackground(true);
        ui->Choice_A->setPalette(pal);
        ui->Choice_A->update();
    }
}


void GameWindow::on_Choice_B_clicked()
{
    resetButtons();
    QString text = ui->Choice_B->text();
    if (text.compare(currQuestion) == 0) {
       QPalette pal = ui->Choice_B->palette();
       pal.setColor(QPalette::Button, QColor(QColorConstants::Green));
       ui->Choice_B->setAutoFillBackground(true);
       ui->Choice_B->setPalette(pal);
       ui->Choice_B->update();
       ui->Next->show();
    }
    else {
        QPalette pal = ui->Choice_B->palette();
        pal.setColor(QPalette::Button, QColor(QColorConstants::Red));
        ui->Choice_B->setAutoFillBackground(true);
        ui->Choice_B->setPalette(pal);
        ui->Choice_B->update();
    }
}


void GameWindow::on_Choice_C_clicked()
{
    resetButtons();
    QString text = ui->Choice_C->text();
    if (text.compare(currQuestion) == 0) {
       QPalette pal = ui->Choice_C->palette();
       pal.setColor(QPalette::Button, QColor(QColorConstants::Green));
       ui->Choice_C->setAutoFillBackground(true);
       ui->Choice_C->setPalette(pal);
       ui->Choice_C->update();
       ui->Next->show();
    }
    else {
        QPalette pal = ui->Choice_C->palette();
        pal.setColor(QPalette::Button, QColor(QColorConstants::Red));
        ui->Choice_C->setAutoFillBackground(true);
        ui->Choice_C->setPalette(pal);
        ui->Choice_C->update();
    }
}


void GameWindow::on_Choice_D_clicked()
{
    resetButtons();
    QString text = ui->Choice_D->text();
    if (text.compare(currQuestion) == 0) {
       QPalette pal = ui->Choice_D->palette();
       pal.setColor(QPalette::Button, QColor(QColorConstants::Green));
       ui->Choice_D->setAutoFillBackground(true);
       ui->Choice_D->setPalette(pal);
       ui->Choice_D->update();
       ui->Next->show();
    }
    else {
        QPalette pal = ui->Choice_D->palette();
        pal.setColor(QPalette::Button, QColor(QColorConstants::Red));
        ui->Choice_D->setAutoFillBackground(true);
        ui->Choice_D->setPalette(pal);
        ui->Choice_D->update();
    }
}


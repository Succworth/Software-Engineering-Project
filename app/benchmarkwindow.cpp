#include "benchmarkwindow.h"
#include "ui_benchmarkwindow.h"
#include "mainmenu.h"

/* TO DO
 * Make it so that users can only guess one time ： Complete
 * Randomize the questions
 * Only display a certain number of questions
 * Display user's score once they've gone through every question
 * Add alphabet
*/

BenchmarkWindow::BenchmarkWindow(QWidget *parent, int i) :
    QMainWindow(parent),
    ui(new Ui::BenchmarkWindow)
{
    ui->setupUi(this);
    lessonNumber = i;
    a = new AnswerKey(i);
    questionNo = 0;
    questionSet = a->getAnswers();
    questionSet = randomize(questionSet);
    ui->Correction->setText("Select an answer");
    ui->Retry->hide();
    displayQuestion();


    QObject::connect(ui->pushButton, &QPushButton::clicked, this, &BenchmarkWindow::open_mainmenu);
}

BenchmarkWindow::~BenchmarkWindow()
{
    delete ui;
}

void BenchmarkWindow::open_mainmenu(){
    hide();
    //do saving and destruction
    MainMenu* mainmenu = new MainMenu(this);
    mainmenu->show();
}

QVector<QString> BenchmarkWindow::randomize(QVector<QString> &choices) {
    QVector<QString> temp;
    while (temp.size() < choices.size()) {
        QString test = choices[rand() % choices.size()];
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
void BenchmarkWindow::displayQuestion() {
    ui->Next->hide();

    currQuestion = questionSet[questionNo];
    questionNo++;

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
    QMovie *movie = new QMovie(path + currQuestion + ".gif");
    ui->label->setMovie(movie);
    ui->label->setScaledContents(true);
    movie->start();
    ui->Next->hide();
}

//Reset button colors
void BenchmarkWindow::resetButtons() {
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

    //Set a text box for direction and reset clicked.
    ui->Correction->setText("Select an answer");
    ui->Retry->hide();
    clicked = false;
}

//Flow of questions
void BenchmarkWindow::on_Next_clicked()
{
    resetButtons();
    displayQuestion();
}


void BenchmarkWindow::on_Choice_A_clicked()
{
    if(!clicked){
        resetButtons();
        QString text = ui->Choice_A->text();
        if (text.compare(currQuestion) == 0) {
           QPalette pal = ui->Choice_A->palette();
           pal.setColor(QPalette::Button, QColor(QColorConstants::Green));
           ui->Choice_A->setAutoFillBackground(true);
           ui->Choice_A->setPalette(pal);
           ui->Choice_A->update();
           ui->Next->show();
           ui->Correction->setText("Correct!");
        }
        else {
            QPalette pal = ui->Choice_A->palette();
            pal.setColor(QPalette::Button, QColor(QColorConstants::Red));
            ui->Choice_A->setAutoFillBackground(true);
            ui->Choice_A->setPalette(pal);
            ui->Choice_A->update();
            ui->Correction->setText("Incorrect, Try again!");
            ui->Retry->show();
            }
        clicked = true;
    }
}


void BenchmarkWindow::on_Choice_B_clicked()
{
    if(!clicked){
        resetButtons();
        QString text = ui->Choice_B->text();
        if (text.compare(currQuestion) == 0) {
           QPalette pal = ui->Choice_B->palette();
           pal.setColor(QPalette::Button, QColor(QColorConstants::Green));
           ui->Choice_B->setAutoFillBackground(true);
           ui->Choice_B->setPalette(pal);
           ui->Choice_B->update();
           ui->Next->show();
           ui->Correction->setText("Correct!");
        }
        else {
            QPalette pal = ui->Choice_B->palette();
            pal.setColor(QPalette::Button, QColor(QColorConstants::Red));
            ui->Choice_B->setAutoFillBackground(true);
            ui->Choice_B->setPalette(pal);
            ui->Choice_B->update();
            ui->Correction->setText("Incorrect, Try again!");
            ui->Retry->show();
        }
        clicked = true;
    }
}


void BenchmarkWindow::on_Choice_C_clicked()
{
    if(!clicked){
        resetButtons();
        QString text = ui->Choice_C->text();
        if (text.compare(currQuestion) == 0) {
           QPalette pal = ui->Choice_C->palette();
           pal.setColor(QPalette::Button, QColor(QColorConstants::Green));
           ui->Choice_C->setAutoFillBackground(true);
           ui->Choice_C->setPalette(pal);
           ui->Choice_C->update();
           ui->Next->show();
           ui->Correction->setText("Correct!");
        }
        else {
            QPalette pal = ui->Choice_C->palette();
            pal.setColor(QPalette::Button, QColor(QColorConstants::Red));
            ui->Choice_C->setAutoFillBackground(true);
            ui->Choice_C->setPalette(pal);
            ui->Choice_C->update();
            ui->Correction->setText("Incorrect, Try again!");
            ui->Retry->show();
        }
        clicked =true;
    }
}


void BenchmarkWindow::on_Choice_D_clicked()
{
    if(!clicked){
        resetButtons();
        QString text = ui->Choice_D->text();
        if (text.compare(currQuestion) == 0) {
           QPalette pal = ui->Choice_D->palette();
           pal.setColor(QPalette::Button, QColor(QColorConstants::Green));
           ui->Choice_D->setAutoFillBackground(true);
           ui->Choice_D->setPalette(pal);
           ui->Choice_D->update();
           ui->Next->show();
           ui->Correction->setText("Correct!");
        }
        else {
            QPalette pal = ui->Choice_D->palette();
            pal.setColor(QPalette::Button, QColor(QColorConstants::Red));
            ui->Choice_D->setAutoFillBackground(true);
            ui->Choice_D->setPalette(pal);
            ui->Choice_D->update();
            ui->Correction->setText("Incorrect, Try again!");
            ui->Retry->show();
        }
        clicked =true;
    }
}

void BenchmarkWindow::on_Retry_clicked()
{
    resetButtons();
}

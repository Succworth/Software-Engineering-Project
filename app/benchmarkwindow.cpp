#include "benchmarkwindow.h"
#include "ui_benchmarkwindow.h"
#include "mainmenu.h"

/* TO DO
 * Make it so that users can only guess one time ： Complete
 * Randomize the questions : Complete
 * Only display a certain number of questions : Done
 * Display user's score once they've gone through every question : Done
 * Add alphabet
*/

BenchmarkWindow::BenchmarkWindow(QWidget *parent, int i, User *user) :
    QMainWindow(parent),
    ui(new Ui::BenchmarkWindow)
{
    ui->setupUi(this);
    lessonNumber = i;
    a = new AnswerKey(i);
    this->user = user;
    questionNo = 0;
    correct = 0;
    questionSet = a->getAnswers();
    questionSet = randomize(questionSet);

    ui->Correction->setText("Select an answer");
    ui->Retry->hide();
    ui->Score->hide();
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
    MainMenu* mainmenu = new MainMenu(this, user);
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
    if (questionNo == 10) {
        endScreen();
    }
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
    if(lessonNumber == 0) { path = ":/Assets/Alphabet/"; }
    QMovie *movie = new QMovie(path + currQuestion + ".gif");
    ui->label->setMovie(movie);
    ui->label->setScaledContents(true);
    movie->start();
    ui->Next->hide();
}

//Reset button colors
void BenchmarkWindow::resetButtons() {
    ui->Choice_A->setStyleSheet("* { border-color: #051a39 }");
    ui->Choice_A->update();

    ui->Choice_B->setStyleSheet("* { border-color: #051a39 }");
    ui->Choice_B->update();

    ui->Choice_C->setStyleSheet("* { border-color: #051a39 }");
    ui->Choice_C->update();

    ui->Choice_D->setStyleSheet("* { border-color: #051a39 }");
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
            ui->Choice_A->setStyleSheet("* { border-color: #00ff00 }");
            ui->Choice_A->update();
            ui->Next->show();
           ui->Correction->setText("Correct!");
           correct++;
        }
        else {
            ui->Choice_A->setStyleSheet("* { border-color: #ff0000 }");
            ui->Choice_A->update();
            ui->Correction->setText("Incorrect, Try again!");
            //ui->Retry->show();
            }
        clicked = true;
    }
    ui->Next->show();
}


void BenchmarkWindow::on_Choice_B_clicked()
{
    if(!clicked){
        resetButtons();
        QString text = ui->Choice_B->text();
        if (text.compare(currQuestion) == 0) {
            ui->Choice_B->setStyleSheet("* { border-color: #00ff00 }");
            ui->Choice_B->update();
            ui->Next->show();
           ui->Correction->setText("Correct!");
           correct++;
        }
        else {
            ui->Choice_B->setStyleSheet("* { border-color: #ff0000 }");
            ui->Choice_B->update();
            ui->Correction->setText("Incorrect, Try again!");
            //ui->Retry->show();
        }
        clicked = true;
    }
    ui->Next->show();
}


void BenchmarkWindow::on_Choice_C_clicked()
{
    if(!clicked){
        resetButtons();
        QString text = ui->Choice_C->text();
        if (text.compare(currQuestion) == 0) {
            ui->Choice_C->setStyleSheet("* { border-color: #00ff00 }");
            ui->Choice_C->update();
            ui->Next->show();
           ui->Correction->setText("Correct!");
           correct++;
        }
        else {
            ui->Choice_C->setStyleSheet("* { border-color: #ff0000 }");
            ui->Choice_C->update();
            ui->Correction->setText("Incorrect, Try again!");
            //ui->Retry->show();
        }
        clicked =true;
    }
    ui->Next->show();
}


void BenchmarkWindow::on_Choice_D_clicked()
{
    if(!clicked){
        resetButtons();
        QString text = ui->Choice_D->text();
        if (text.compare(currQuestion) == 0) {
            ui->Choice_D->setStyleSheet("* { border-color: #00ff00 }");
            ui->Choice_D->update();
            ui->Next->show();
           ui->Correction->setText("Correct!");
           correct++;
        }
        else {
            ui->Choice_D->setStyleSheet("* { border-color: #ff0000 }");
            ui->Choice_D->update();
            ui->Correction->setText("Incorrect, Try again!");
            //ui->Retry->show();
        }
        clicked =true;
    }
    ui->Next->show();
}

void BenchmarkWindow::on_Retry_clicked()
{
    resetButtons();
}

void BenchmarkWindow::endScreen() {
    ui->Choice_A->hide();
    ui->Choice_B->hide();
    ui->Choice_C->hide();
    ui->Choice_D->hide();
    ui->label->hide();
    ui->Correction->hide();

    ui->Score->show();
    ui->Score->setText(QString::number((double)correct/(questionNo)*100) + "%");
}

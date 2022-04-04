#include "mainmenu.h"
#include "ui_mainmenu.h"
//temp include
#include "answerkey.h"

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    init_menu();

    //temp code below
    /*
    AnswerKey a = AnswerKey(3);
    //QString question = a.getQuestion();
    QVector<QString> test = a.getQuestions();
    for (auto s : test) {
        qDebug() << s;
    }
    */
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::setUserText(QString name, QString id){
    ui->label_2->setText("User: " + name + ", " + id);
}

void MainMenu::init_menu(){
    unsigned int numLessons = 20;
    unsigned int numBenchmarks = 20;

    //set up Lessons
    QVBoxLayout* lesson_layout = new QVBoxLayout(ui->frame_2);

    for(unsigned int i = 1; i < numLessons+1; i++){

        QHBoxLayout* row = new QHBoxLayout();

        QLabel* lessonName = new QLabel(QStringLiteral("Lesson %1").arg(i));
        QPushButton* goToLesson = new QPushButton("Start Lesson");

        row->addWidget(lessonName);
        row->addWidget(goToLesson);

        lesson_layout->addLayout(row);
    }
    //set up Benchmarks
    QVBoxLayout* benchmark_layout = new QVBoxLayout(ui->frame_3);

    for(unsigned int i = 1; i < numLessons+1; i++){

        QHBoxLayout* row = new QHBoxLayout();

        QLabel* benchmarkName = new QLabel(QStringLiteral("Benchmark %1").arg(i));
        QPushButton* goToBenchmark = new QPushButton("Start Benchmark");

        row->addWidget(benchmarkName);
        row->addWidget(goToBenchmark);

        benchmark_layout->addLayout(row);
    }

}

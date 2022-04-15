#include "mainmenu.h"
#include "ui_mainmenu.h"
//temp include
#include "answerkey.h"
#include "gamewindow.h"

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    init_menu();

    //temp code below
    /*
    AnswerKey a = AnswerKey(2);
    QString question = a.getQuestion();
    QVector<QString> test = a.getChoices(question, 3);
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
    unsigned int numLessons = 30;
    //unsigned int numBenchmarks = 30;

    //set up Lessons
    QVBoxLayout* lesson_layout = new QVBoxLayout(ui->frame_2);
    QPushButton **lessonArray = new QPushButton*[numLessons];
    for(unsigned int i = 0; i < numLessons+1; i++){

        QHBoxLayout* row = new QHBoxLayout();

        QLabel* lessonName = new QLabel(QStringLiteral("Lesson %1").arg(i));
        if(i == 0){ lessonName = new QLabel("Alphabet"); }
        QPushButton* goToLesson = new QPushButton("Start Lesson");

        row->addWidget(lessonName);
        row->addWidget(goToLesson);

        lesson_layout->addLayout(row);

        lessonArray[i] = goToLesson;
        QObject::connect(lessonArray[i], &QPushButton::clicked, this, [=] {
                            open_lesson(i);
                         });

    }
    //set up Benchmarks
    QVBoxLayout* benchmark_layout = new QVBoxLayout(ui->frame_3);

    QPushButton **benchmarkArray = new QPushButton*[numLessons];
    for(unsigned int i = 0; i < numLessons+1; i++){

        QHBoxLayout* row = new QHBoxLayout();

        QLabel* benchmarkName = new QLabel(QStringLiteral("Benchmark %1").arg(i));
        if(i == 0){ benchmarkName = new QLabel("Alphabet Benchmark"); }
        QPushButton* goToBenchmark = new QPushButton("Start Benchmark");

        row->addWidget(benchmarkName);
        row->addWidget(goToBenchmark);

        benchmark_layout->addLayout(row);

        benchmarkArray[i] = goToBenchmark;
        QObject::connect(benchmarkArray[i], &QPushButton::clicked, this, [=] {
                            open_benchmark(i);
                         });
    }

}

void MainMenu::open_lesson(int i){
    hide();
    gameWindow = new GameWindow(this, i);
    gameWindow->show();
}

void MainMenu::open_benchmark(int i){
    hide();
    benchmarkWindow = new BenchmarkWindow(this, i);
    benchmarkWindow->show();
}

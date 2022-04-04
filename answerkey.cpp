#include "answerkey.h"

AnswerKey::AnswerKey(int i) {
    QDir exeDir(QCoreApplication::applicationDirPath());
    qDebug() <<  exeDir.path()+"/Assets.rcc";
    QResource::registerResource(exeDir.path()+"/Assets.rcc");
    numWords = 0;
    //example of how directories look now: ":/Assets/Common Words and Phrases 1/again.mp4"
    QString path = ":/Assets/Common Words and Phrases "+QString::number(i)+"/";
    QDirIterator it(path, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        QFileInfo fi(it.next());
        answers.append(fi.baseName());
        qDebug() << fi.baseName();
        numWords++;
    }
}

QVector<QString> AnswerKey::getAnswers() {
    return answers;
}

QVector<QString> AnswerKey::getChoices(QString answer, int n) {
    QVector<QString> choices;
    choices.push_back(answer);
    while(n > 0) {
        QString random = answers[rand() % numWords];
        if(choices.contains(random)) {
            continue;
        }
        else {
            choices.push_back(random);
            n--;
        }
    }
    return choices;
}

QString AnswerKey::getQuestion() {
    return answers[rand() % numWords];
}

QVector<QString> AnswerKey::getQuestions() {
    QVector<QString> random;
    QVector<QString> temp = answers;
    while(temp.size() != 0) {
        int i = rand() % temp.size();
        random.push_back(temp.takeAt(i));
    }
    return random;
}

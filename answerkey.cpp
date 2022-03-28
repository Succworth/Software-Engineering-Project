#include "answerkey.h"

AnswerKey::AnswerKey(int i) {
    QDir dir(QDir::currentPath());
    dir.cdUp();
    dir.cd("Software-Engineering-Project/");
    qDebug() <<  dir.path()+"/Assets.rcc"; //make sure this path is correct for testing
    QResource::registerResource(dir.path()+"/Assets.rcc");
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

QString AnswerKey::getRandom(QString answer) {
    QString random = answers[rand() % numWords];
    if (random.compare(answer) == 0) {
        getRandom(answer);
    }
    return random;
}

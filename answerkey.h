#ifndef ANSWERKEY_H
#define ANSWERKEY_H

#include <random>
#include <QDirIterator>
#include <QDebug>
#include <QVector>
#include <QResource>
#include <QCoreApplication>

class AnswerKey {
private:
    QVector<QString> answers;
    int numWords;
public:
    AnswerKey(int i);
    QVector<QString> getAnswers();
    QString getRandom(QString answer);
};

#endif // ANSWERKEY_H

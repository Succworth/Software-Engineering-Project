#include <QtTest>
#include <QCoreApplication>
#include <QDebug>

// add necessary includes here
#include "answerkey.h"

class login : public QObject
{
    Q_OBJECT

public:
    login();
    ~login();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

login::login()
{

}

login::~login()
{

}

void login::initTestCase()
{

}

void login::cleanupTestCase()
{

}

void login::test_case1()
{
    QString str = "Hello";
    QCOMPARE(str.toUpper(), QString("HELLO"));
    AnswerKey anskey(1);
    qDebug() << anskey.getAnswers();
    QVERIFY(anskey.getAnswers().length() == 24);
}

QTEST_MAIN(login)

#include "tst_login.moc"

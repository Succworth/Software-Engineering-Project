#include <QtTest>
#include <QCoreApplication>
#include <QDebug>

// add necessary includes here
#include "answerkey.h"
#include "crackingasl.h"
#include "ui_crackingasl.h"
#include "ui_mainmenu.h"

class login : public QObject
{
    Q_OBJECT

public:
    login();
    ~login();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_answerkey();
    void test_login();

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

void login::test_answerkey()
{
    QVector<QVector<QString>> allAnswers;
    allAnswers.append({"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"});
    allAnswers.append({"hearing","meaning","understand","hello","slow","dont_understand","your","no","like (emotion)","again","name","learn","deaf","meet","where","student","thank you","who","why","teacher","what","nice","yes","sign"});
    allAnswers.append({"boy","brother","child","children","dad","divorce","fingerspell","girl","grandma","grandpa","have","her","hey","his","how many","how","its","live (address)","many","marriage","mom","my","our","parents (mom and dad)","single (not married)","sister","their","work","yours"});
    allAnswers.append({"all","ask (inquire)","bad","bathroom","best","better","big","city","class","come","dont-like","family","favorite","fine (agreement)","from","go","good","grow up","here","house","more","need","school","small","so-so","think","want"});
    //allAnswers.append({});
    //allAnswers.append({});
    //allAnswers.append({});
    //allAnswers.append({});  //TODO: Fill out for all 30
    //allAnswers.append({});
    //allAnswers.append({});
    //allAnswers.append({});
    for(int i = 0; i < allAnswers.length(); i ++){
        AnswerKey anskey(i);
        QVector<QString> res = anskey.getAnswers();
        for(int j = 0; j < allAnswers[i].length(); j++){
            QVERIFY(res.contains(allAnswers[i][j]));
        }
    }
}

void login::test_login()
{
    CrackingASL casl;
    QTest::keyClicks(casl.ui->lineEdit, "aye");
    QCOMPARE(casl.ui->lineEdit->text(), QString("aye"));
    QTest::keyClicks(casl.ui->lineEdit_2, "12345678");
    QCOMPARE(casl.ui->lineEdit_2->text(), QString("12345678"));
    QTest::mouseClick(casl.ui->pushButton, Qt::LeftButton);
    QCOMPARE(casl.mainMenu->ui->label_2->text(), "User: 12345678, aye");
}

QTEST_MAIN(login)

#include "tst_login.moc"

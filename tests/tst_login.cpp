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
    allAnswers.append({"angry","aunt","baby","bed","bedroom","box","brush-teeth","cry","daughter","dont-want","excuse me","feel","friend","happy","help","hurt","idea","if","lay down","love","room","sad","son","sorry","stand","stop","suppose (imagine)","uncle","wash"});
    allAnswers.append({"can","car","church","computer","doctor","drive","email","give","home","in","internet","move","movie","nurse","out","play (drama)","put","sit","stand","stay","store","video","walk","watch","with"});
    allAnswers.append({"annually","black","blue","brown","color","draw (art)","everyday","finish","future","green","last year","long","next year","now","old","orange","paper","past","red","self","tomorrow","wait","when","white","year","yellow"});
    allAnswers.append({"and","apple","candy","cereal","cheese","cookie","cup","drink","eat","egg","food","full","hamburger","hotdog","hungry","milk","pizza","popcorn","soup","total","water"});
    allAnswers.append({"backpack","basket","battery","belt","change","clothes","dirty","dress (action)","electricity","glasses","hearing aid","jacket","off","on","pants","pick up","shirt","shoes","socks","underwear","washing machine","which","zip (up)"});
    allAnswers.append({"basement","bathtub","close window","closet","door","dresser","dryer","garage","kitchen","light","microwave","open door","open window","open","refrigerator","say","shower","single","sink","sofa","someone","something","stove (fingerspell)","table","there","toothpaste","trash can","trash","what-kind","window","with","yesterday"});
    allAnswers.append({"adopt","bird","book","cat","certainly","cow","dog","fish","get","horse","insect","know","look like","o'clock","pet","read","same","say","some","take","time","true"});
    allAnswers.append({"always","anxious","backward","but","call","cannot","for","great","little","make","near","nervous","never","new","oh i see","or","people","phone","sometimes","talk","thing","whatever","wonderful","yell"});
    allAnswers.append({"afternoon","day","equal","everyday","friday","habit","hour","minute","monday","month","morning","night","noon","saturday","second","sunday","thursday","tuesday","wednesday","week","weekend","what do","yesterday"});
    allAnswers.append({"almost","Article","campus","caption","college","easy","exam","false","flashlight","graduate","hard of hearing","hard","highschool","interpreter","list","note","paper","research","square","write","wrong"});
    allAnswers.append({"autumn","breeze","cold","cool","deodorant","enjoy","freeze","hit the sack (go to bed)","hot","man","moon","morning","rain","sick","sleep","snow","spring","summer","sun","use","vacation","wake-up","warm","weather","winter","woman"});
    allAnswers.append({"aide","babysitter","boss","brother in law","cook","farm","father in law","firefighter","library","major","neighbor","photographer","picture","police","president","printer","program","scientist","secretary","self","stepfather","stepmother"});
    allAnswers.append({"after","appointment","before","best","better","do-what","do","end","few","first","half-hour","last","late","look","middle","midnight","most","next","not-yet","often","recent","see","soon"});
    allAnswers.append({"banana","beer","breakfast","cup","dinner","french-fries","french-toast","grapes","ketchup","lunch","many","mayonnaise","mustard","pancake","pepper","pickle","plate","salad","salt","sink","soap","soda-pop","soup"});
    allAnswers.append({"accident","airplane","bicycle","boat","building","elevator","enjoy","find","fly","fun","garage","helicopter","key","leave","lost","motorcycle","practice","ride","rocket","search","subway","ticket","train","travel","truck"});
    allAnswers.append({"afraid","angry","bored","brave","chat","embarrassed","friendly","frustrated","happy","insult","interesting","jealous","lonely","mean","meaning","nervous","proud","silly","stuck-up","surprise","tired"});
    allAnswers.append({"buzz-cut","curly-hair","cute","eye","face","fat","fool","hair","long-hair","look-like","ordinary","pretty","regular","short-hair","short","skinny","strong","tall","thick","thin","ugly","weak"});
    allAnswers.append({"apply","army","borrow","bus","control","dance","dentist","fire","fish","fishing","fly","haircut","hire","keep","law","mail","manager","paint","painter","pastor","preach","priest","resume","send","takecare","wrench"});
    allAnswers.append({"broke","business","busy","buy","cent","cost","dollar","early","earn","free","government","letter","money","narrator","pay","register","retire","show","silver","subscribe"});
    allAnswers.append({"apartment","bookstore","cafeteria","divide","dorm","english","examine","explain","fail","flunk","freshman","junior","math","minus","number","pass","plus","post","senior","sophomore","sum","worse"});
    allAnswers.append({"accept","decline","decrease","dont-care","during","else","enough","equal","good-enough","how-much","improve","increase","less-than","limit","mischievous","more-than","strange","success","surplus","than","turn-off","worry"});
    allAnswers.append({"area","bring","come","dont-care","east","exact","far","fast","field","front","hurry","left","move","near","north","parking-lot","perfect","play","right","since","south","west","wow"});
    allAnswers.append({"bright","dark","dig","dont-care","flower","forget","fun","grass","heavy","laugh","light","low","mountains","outside","plant","remember","tall","topic","tree"});
    allAnswers.append({"bread","butter","cabinet","cake","coffee","delicious","dozen","feed","meat","ounce","pie","pound","smell","taste","tea","vegetables","wash-dishes","wine"});
    allAnswers.append({"blanket","button","clothes","copy","diaper","dress","hair-dryer","hat","match","necklace","plaids","scarf","sew","shave","tie","touch","towel"});
    allAnswers.append({"able","bald","beard","card","caucasian","cousin","disappear","happen","hide","impossible","music","mustache","plan","secret","seek","seem","show-up","shy","smart","stupid","yourself"});
    allAnswers.append({"cellphone","drawer","elevator","factory","floor","furniture","give-up","janitor","measure","meeting","prefer","responsible","restaurant","start","street","wall","watch"});
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
    QCOMPARE(casl.mainMenu->ui->label_2->text(), "User: aye, 12345678");
}

QTEST_MAIN(login)

#include "tst_login.moc"

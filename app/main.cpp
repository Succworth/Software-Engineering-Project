#include "crackingasl.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CrackingASL w;
    w.show();
    return a.exec();
}

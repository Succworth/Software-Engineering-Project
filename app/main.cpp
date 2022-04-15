#include "crackingasl.h"

#include <QApplication>

#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDir exeDir(QCoreApplication::applicationDirPath());
    qDebug() <<  exeDir.path() + "/Darkeum.qss";
    QFile styleSheetFile(exeDir.path()+"/Darkeum.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(styleSheet);
    CrackingASL w;
    w.show();
    return a.exec();
}

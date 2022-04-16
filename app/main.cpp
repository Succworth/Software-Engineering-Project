#include "crackingasl.h"

#include <QApplication>

#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDir exeDir(QCoreApplication::applicationDirPath());
    QResource::registerResource(exeDir.path()+"/Assets.qrc");
    QString path = ":/Assets/Darkeum.qss";

    qDebug() <<  path;
    QFile styleSheetFile(path);
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(styleSheet);
    CrackingASL w;
    w.show();
    return a.exec();
}

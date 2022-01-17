#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QFile>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

 // set the app style sheet
    QFile styleSheetFile("./EasyCode.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(styleSheet);

    MainWindow w;
    w.show();
    return a.exec();
}

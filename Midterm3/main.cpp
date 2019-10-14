#include "mainwindow.h"
#include <QApplication>
#include "valueiteration.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    valueIteration MDP;
    MDP.runValueIterator();

    return a.exec();
}

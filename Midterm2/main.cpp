#include <QCoreApplication>
#include "proofengine.h"
#include <QString>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QString KB = "A,B,AB=>L,AP=>L,BL=>M,LM=>P,P=>Q";
    QString KBB = "A=>G,AG=>F,C,C=>A,FC=>H,H=>F,HF=>M,MA=>B";

    ProofEngine Midterm2(KBB, "B");

    if(Midterm2.FCentails())
        qDebug() << "SUCCESS";
    else
        qDebug() << "FAILED";

    return a.exec();
}

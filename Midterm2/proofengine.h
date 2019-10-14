#ifndef PROOFENGINE_H
#define PROOFENGINE_H

#include <QString>
#include <QMap>
#include <QList>
#include <QtDebug>

class ProofEngine
{
public:
    ProofEngine();
    ProofEngine(QString KB, QString q);
    bool FCentails();
private:
    QStringList _KB;
    QStringList AGENDA;
    QStringList KB_PREMISES;
    QStringList KB_CONCLUSIONS;
    QMap<QString, int> COUNT;
    QMap<QString, bool> INFERRED;
    QString _q;
};

#endif // PROOFENGINE_H

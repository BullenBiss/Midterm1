#include "proofengine.h"

ProofEngine::ProofEngine()
{

}

ProofEngine::ProofEngine(QString KB, QString q)
{
    _KB = KB.split(",");
    _q = q;

    for(int i = 0; i < _KB.size(); i++)
    {
          /* Take the KB and insert only the premises with number of symbols into COUNT */
        if(_KB.value(i).contains("=>")) // Remove implication arrow
        {
            COUNT.insert(_KB.value(i).mid(0, _KB.value(i).indexOf("=")), _KB.value(i).mid(0, _KB.value(i).indexOf("=")).size());
            KB_PREMISES.append(_KB.value(i).mid(0, _KB.value(i).indexOf("=")));
            KB_CONCLUSIONS.append(_KB.value(i).mid(_KB.value(i).indexOf(">")+1, _KB.value(i).indexOf(">")+1));
        }
        else
        {
            COUNT.insert(_KB.value(i), _KB.value(i).size());

        }

          /* Add only one instance of each symbol and set to initial value false */
        for(int j = 0; j < _KB.value(i).size(); j++)
        {
            if(!INFERRED.contains(_KB.value(i).at(j)) && _KB.value(i).at(j) != "=" && _KB.value(i).at(j) != ">")
                INFERRED.insert(_KB.value(i).at(j), false);
        }

        if(_KB.value(i).size() == 1)
        {
            AGENDA.append(_KB.value(i));
        }
    }

    qDebug() << "KB: " << KB;
    qDebug() << "Query: " << q;
    qDebug() << "\n";

}

bool ProofEngine::FCentails()
{
    QString p;
    int loopCounter = 0;

    //COUNT, INFERRED and AGENDA is declared in proofengine.h

    while(!AGENDA.empty())
    {
        p = AGENDA.front();
        AGENDA.pop_front();

        if(p == _q)
            return true;

        if(INFERRED.value(p) == false)
        {
            INFERRED.insert(p, true);

            /* Loop through only premises */
            for(int i = 0; i < KB_PREMISES.size(); i++)
            {
                if(KB_PREMISES.value(i).contains(p))
                {
                    /* Decrement count */
                    int tempCount = COUNT.value(KB_PREMISES.value(i));
                    tempCount--;

                    /*Add conclusion to agenda*/
                    if(tempCount == 0)
                    {
                        AGENDA.append(KB_CONCLUSIONS.value(i));
                    }

                    if(tempCount >= 0)
                        COUNT.insert(KB_PREMISES.value(i), tempCount);

                }
            }
        }
        loopCounter++;
        qDebug() << "Loop " << "(" << loopCounter << ")";
        qDebug() << "INFERRED:" << INFERRED;
        qDebug() << "AGENDA" << AGENDA;
        qDebug() << "\n";
    }

    return false;
}

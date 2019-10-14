#ifndef VALUEITERATION_H
#define VALUEITERATION_H

#include "state.h"
#include <QDebug>
#include <QThread>
class valueIteration
{
public:
    valueIteration();
    void runValueIterator();
    double bellmanEquation(int x, int y);
    void updateDebug();
private:
    float gamma;
    float delta;
    double R;
    state s[4][4];

};

#endif // VALUEITERATION_H

#include "valueiteration.h"

valueIteration::valueIteration()
{
    gamma = 1;
    delta = 0;
    R = -0.2;


    s[1][1].U = -1;
    s[1][2].U = -1;
    s[3][0].U = -1;
    s[3][1].U = -1;
    s[3][2].U = 1;

}

void valueIteration::runValueIterator()
{
    for(int iterations = 0; iterations < 1; iterations++)
    {
        for(int y = 0; y < 4; y++)
        {
            for(int x = 0; x < 4; x++)
            {
                s[x][y].U += bellmanEquation(x, y);
                updateDebug();
                QThread::msleep(500);
            }
        }
    }




}

double valueIteration::bellmanEquation(int x, int y)
{
    double sumPU = 0;
    double tempValue = 0;
    int xPrime = x;
    int yPrime = y;

    //Check action up
    if(y != 3)      //up
        yPrime++;
    tempValue += 0.8 * s[xPrime][yPrime].U;
    yPrime = y;

    if(x != 3)      //left
        xPrime++;
    tempValue += 0.1 * s[xPrime][yPrime].U;
    xPrime = x;

    if(x != 0)      //right
        xPrime--;
    tempValue += 0.1 * s[xPrime][yPrime].U;
    xPrime = x;

    if(tempValue >= sumPU)
    {
        sumPU = tempValue;
        s[x][y].optimalDirection = 'N';
    }
    tempValue = 0;

    //Check action left
    if(y != 3)      //up
        yPrime++;
    tempValue += 0.1 * s[xPrime][yPrime].U;
    yPrime = y;

    if(y != 0)      //down
        yPrime--;
    tempValue += 0.1 * s[xPrime][yPrime].U;
    yPrime = x;

    if(x != 0)      //left
        xPrime--;
    tempValue += 0.8 * s[xPrime][yPrime].U;
    xPrime = x;

    if(tempValue >= sumPU)
    {
        sumPU = tempValue;
        s[x][y].optimalDirection = 'W';
    }
    tempValue = 0;


    //Check action down
    if(y != 0)      //down
        yPrime--;
    tempValue += 0.8 * s[xPrime][yPrime].U;
    yPrime = x;

    if(x != 0)      //left
        xPrime--;
    tempValue += 0.1 * s[xPrime][yPrime].U;
    xPrime = x;

    if(x != 0)      //right
        xPrime--;
    tempValue += 0.1 * s[xPrime][yPrime].U;
    xPrime = x;

    if(tempValue >= sumPU)
    {
        sumPU = tempValue;
        s[x][y].optimalDirection = 'S';
    }
    tempValue = 0;


    //Check action right
    if(y != 0)      //down
        yPrime--;
    tempValue += 0.1 * s[xPrime][yPrime].U;
    yPrime = x;

    if(y != 3)      //up
        yPrime++;
    tempValue += 0.1 * s[xPrime][yPrime].U;
    yPrime = y;

    if(x != 0)      //right
        xPrime--;
    tempValue += 0.8 * s[xPrime][yPrime].U;
    xPrime = x;

    if(tempValue >= sumPU)
    {
        sumPU = tempValue;
        s[x][y].optimalDirection = 'E';
    }

    return R + sumPU;
}

void valueIteration::updateDebug()
{

    qDebug() << "[" << s[0][3].U << s[0][3].optimalDirection << "]"
             << "[" << s[1][3].U << s[1][3].optimalDirection << "]"
             << "[" << s[2][3].U << s[2][3].optimalDirection << "]"
             << "[" << s[3][3].U << s[3][3].optimalDirection << "]";

    qDebug() << "[" << s[0][2].U << s[0][2].optimalDirection << "]"
             << "[" << s[1][2].U << s[1][2].optimalDirection << "]"
             << "[" << s[2][2].U << s[2][2].optimalDirection << "]"
             << "[" << s[3][2].U << s[3][2].optimalDirection << "]";

    qDebug() << "[" << s[0][1].U << s[0][1].optimalDirection << "]"
             << "[" << s[1][1].U << s[1][1].optimalDirection << "]"
             << "[" << s[2][1].U << s[2][1].optimalDirection << "]"
             << "[" << s[3][1].U << s[3][1].optimalDirection << "]";

    qDebug() << "[" << s[0][0].U << s[0][0].optimalDirection << "]"
             << "[" << s[1][0].U << s[1][0].optimalDirection << "]"
             << "[" << s[2][0].U << s[2][0].optimalDirection << "]"
             << "[" << s[3][0].U << s[3][0].optimalDirection << "]";

    qDebug() << "\n";
}


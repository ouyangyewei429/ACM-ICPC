/*
PROG:   HangOver
ID  :   ouyangyewei
LANG:   C++
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

const double EPS = 1e-10;

int i, cards;
double c, sum;

int main()
{
    while (~scanf("%lf", &c), c!=0.00)
    {
        cards=0, sum=0.0;
        for (i=2; sum<c; ++i)
        {
            sum += (1.0/i);
            ++cards;
        }// count
        
        printf("%d card(s)\n", cards);
    }// end of while
    
    return 0;
}

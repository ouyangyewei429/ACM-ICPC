/*
PROG:   Calling Extraterrestrial Intelligence Again
ID  :   ouyangyewei
LANG:   C++
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

const int maxn = 100004;

double fac, rate;
int    M, A, B, i, j, p, q, area;
bool   IsPrime[maxn]={true, true, false};

int main()
{
    for (i=2; i<=(int)sqrt(1.0*maxn); ++i)
    {
        if (!IsPrime[i])
        {
            for (j=i*i; j<=maxn; j+=i)
                IsPrime[j] = true;
        }
    }// Prime number
    
    while (~scanf("%d %d %d", &M, &A, &B), M+A+B!=0)
    {
        area=-1, fac=1.0*A/B;
        for (i=1; i<=(int)sqrt(1.0*M); ++i)
        {
            for (j=i; j<=M&&i*j<=M; ++j)
            {
                if (!IsPrime[i] && !IsPrime[j])
                {
                    rate=1.0*i/j;
                    if (fac<=rate && rate<=1 && i*j>area)
                        p=i, q=j, area=i*j;
                }
            }// Loop_2
        }// Loop_1
        
        printf("%d %d\n", p, q);
    }// End of while
    
    return 0;
}

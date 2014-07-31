/*
PROG:   Goldbach's Conjecture
ID  :   ouyangyewei
LANG:   C++
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

const int maxn = (1<<16);

int  i, j, N, cnt;
bool IsNotPrime[maxn]={true, true, false};

int main()
{
    for (i=2; i<=(int)sqrt(1.0*maxn); ++i)
    {
        if (!IsNotPrime[i])
        {
            for (j=i*i; j<=maxn; j+=i)
                IsNotPrime[j] = true;
        }
    }// IsPrime
    
    while (~scanf("%d", &N), N!=0)
    {
        cnt = 0;
        for (i=2; i<=N/2; ++i)
        {
            if (!IsNotPrime[i] && !IsNotPrime[N-i])
            {
              //  printf("%d %d\n", i, N-i);
                ++cnt;
            }    
        }// counting
        
    //    printf("-----------------\n");
        printf("%d\n", cnt);
    }// End of while
    
    return 0;
}

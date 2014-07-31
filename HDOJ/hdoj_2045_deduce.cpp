/*
PROG:   不容易系列之(3)—— LELE的RPG难题
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int N, i;
__int64 F[55]={0,3,6,6};

int main()
{
    for (i=4; i<=50; ++i)
        F[i] = (F[i-2]<<1) + F[i-1];

    while (~scanf("%d", &N))
    {
        printf("%I64d\n", F[N]);
    }
    
    return 0;
}

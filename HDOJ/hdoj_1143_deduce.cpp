/*
PROG:   Tri Tiling
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int N, i, j;
__int64 F[35]={1,0,3};

int main()
{
    for (i=4; i<=31; i+=2)
    {
        F[i] = F[i-2]*3;
        for (j=4; j<=i; j+=2)
            F[i] += (F[i-j]<<1);
    }// deduce
    
    while (~scanf("%d", &N), N!=-1)
    {
        printf("%I64d\n", F[N]);
    }// End of while
    
    return 0;
}

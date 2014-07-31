/*
PROG:   Binary Numbers
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

const int maxn = 35;

int  T, N, i, cnt, rt, binary[maxn];

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        for (cnt=0; N!=0; ++cnt)
        {
            binary[cnt] = N%2;
            N >>= 1;
        }// trans to 2's complement
        
        for (i=0, rt=0; i<cnt; ++i)
        {
            if ( binary[i] )
            {
                printf(rt==0 ? "%d":" %d", i);
                rt = 1;
            }
        }// output the result
        printf("\n");
    }// End of while
    
    return 0;
}

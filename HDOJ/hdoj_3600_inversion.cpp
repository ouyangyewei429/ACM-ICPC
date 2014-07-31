/*
PROG:   Simple Puzzle
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

const int maxn = 302;
const int INF = 0x3F3F3F3F;

int N, inverNums, i, j, puzzle[maxn*maxn];

int main()
{
    while (~scanf("%d", &N), N!=0)
    {
        for (i=0; i<N*N; ++i)
            scanf("%d", &puzzle[i]);
            
        inverNums = 0;
        for (i=0; i<N*N-1; ++i)
        {
            for (j=i+1; j<N*N; ++j)
            {
                if ( puzzle[j]<puzzle[i] )
                    ++inverNums;
            }
        }// get the inversion
        if ( inverNums&1 )
            printf("YES\n");
        else
            printf("NO\n");
    }// end of while
    
    return 0;
}

/*
PROG:   ∆∆“Î√‹¬Î
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

const int maxn = 1004;

char keys, decode[maxn];
int  i, N, t, code[maxn];

int main()
{
    while (~scanf("%d", &N))
    {
        for (i=0; i<N; ++i)
            scanf("%d", &code[i]);
        
        for (keys='A'; keys<='Z'; ++keys)
        {
            for (i=0; i<N; ++i)
            {
                t = keys^code[i];
                if ( t<'A' || t>'Z' )   break;
            }
            if ( i==N ) break;
        }// check all code and find the keys
        
        for (i=0; i<N; ++i)
            printf("%c", keys^code[i]);
        printf("\n");
    }// end of while
    
    return 0;
}

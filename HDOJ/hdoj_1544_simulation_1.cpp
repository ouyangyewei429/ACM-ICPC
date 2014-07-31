/*
PROG:   Palindromes
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

const int maxn = 5004;

char ss[maxn]={0};
int  N, i, k, cnt, slen;

int main()
{
    while (EOF != scanf("%s", ss))
    {
     //   fflush(stdin);
        cnt = slen = strlen(ss);
        for (i=0; i<slen; ++i)
        {
            for (k=1; k<=(slen>>1); ++k)
            {
                if ( i-k<0 || i+k>slen || ss[i-k]!=ss[i+k] )
                    break;
                
                ++cnt;
            }// bunch's length is odd
            for (k=1; k<=(slen>>1); ++k)
            {
                if ( i-k<0 || i+k-1>slen || ss[i-k]!=ss[i+k-1] )
                    break;
                
                ++cnt;
            }// bunch's length is even
        }
        
        printf("%d\n", cnt);
    }// End of while
    
    return 0;
}

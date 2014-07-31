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
int  N, i, j, k, cnt, slen;

bool CanTakeIt(int len, int mid)
{
    if ( len&1 )
    {
        for (k=1; k<=(len>>1); ++k)
        {
            if ( ss[mid-k]!=ss[mid+k] )
                return false;
        }
        
        return true;
    }// Length is odd
    else
    {
        for (k=1; k<=(len>>1); ++k)
        {
            if ( ss[mid-k]!=ss[mid+k-1] )
                return false;
        }
        
        return true;
    }// Length is Even
}// CanTakeIt

int main()
{
    while (EOF != scanf("%s", ss))
    {
     //   fflush(stdin);
        cnt = slen = strlen(ss);
        for (i=2; i<=slen; ++i)
        {
            for (j=(i>>1); j<slen; ++j)
            {
                if ( CanTakeIt(i, j) )
                    ++cnt;
            }
        }// Main Process
        
        printf("%d\n", cnt);
    }// End of while
    
    return 0;
}

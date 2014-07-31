/*
PROG:   xxx¶¨ÂÉ
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int cnt, N;

int main()
{
    while ( ~scanf("%d", &N), N!=0 )
    {
        for (cnt=0; N!=1; ++cnt)
        {
            if ( N&1 )
                N = (N*3+1)>>1;
            else
                N >>= 1;
        }// End of for
        
        printf("%d\n", cnt);
    }// End of while
    
    return 0;
}

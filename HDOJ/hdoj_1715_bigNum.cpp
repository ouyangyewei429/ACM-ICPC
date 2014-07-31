/*
PROG:   ´ó·Æ²¨Êý
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define DEBUG 0

const int maxn = 226;

char fib[1002][maxn]={0};
int  T, k, i, j, alen, blen, clen, bignum[maxn];

int main()
{
#if DEBUG
    freopen("E:\\hdoj_1715.txt", "r", stdin);
    freopen("E:\\hdoj_1715_1.txt", "w", stdout);
#endif

    strcpy(fib[1], "1");
    strcpy(fib[2], "1");
    strcpy(fib[3], "2");
    strcpy(fib[4], "3");
    for (i=5; i<=1000; ++i)
    {
        //memset(bignum, 0, sizeof(bignum));

        alen = strlen( fib[i-1] );
        blen = strlen( fib[i-2] );
        clen = alen>blen ? alen:blen;
        
        for (j=0; j<alen; ++j)  // get fib[i-1]
            bignum[j] = ( fib[i-1][alen-j-1]-'0' );
        
        for (j=0; j<blen; ++j)  // add fib[i-2]
            bignum[j] += ( fib[i-2][blen-j-1]-'0' );
        
        for (j=0; j<=clen; ++j)
        {
            if ( bignum[j]>9 )
                bignum[j+1]+=bignum[j]/10, bignum[j]%=10;
        }
        
        clen = bignum[clen] ? clen+1:clen;
        for (j=0; j<clen; ++j)
            fib[i][j] = bignum[clen-j-1]+'0';
        fib[i][j] = '\0';
    }// BigNums
    
    scanf("%d", &T);
    while ( T-- )
    {
        scanf("%d", &k);
        printf("%s\n", fib[k]);
    }// End of while
    
    return 0;
}

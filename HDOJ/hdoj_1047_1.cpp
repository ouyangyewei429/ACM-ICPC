/*
PROG:   Integer Inquiry
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <memory.h>
using namespace std;

#define DEBUG 0

const int maxn = 140;

char line[maxn];
int  T, sign, slen, maxLen, i, bignum[maxn];

int main()
{
#if DEBUG
    freopen("E:\\hdoj_1047.txt", "r", stdin);
    freopen("E:\\hdoj_1047_ans.txt", "w", stdout);
#endif

    scanf("%d", &T);
    while ( T-- )
    {
        maxLen = 0;
        memset(line, 0, sizeof(line));
        memset(bignum, 0, sizeof(bignum));
        while ( cin >> line )
        {
            if ( !strcmp(line, "0") )   break;
            
            slen = strlen( line );
            for (i=0; i<slen; ++i)
                bignum[i] += (line[slen-i-1]-'0');
            
            maxLen = maxLen>slen ? maxLen:slen;
            for (i=0; i<=maxn; ++i)
            {
                if ( bignum[i]>9 )
                    bignum[i+1]+=bignum[i]/10, bignum[i]%=10;
            }
            
            memset(line, 0, sizeof(line));
        }

        sign = 0;
        for (i=maxLen+10; i>=0; --i)
        {
            if ( bignum[i] && sign==0 )
                sign = 1;
            if ( sign || i==0 )
                printf("%d", bignum[i]);
        }
            
        if ( T!=0 )
            printf("\n\n");
        else
            printf("\n");
    }// End of while
    
    //system("pause");
    return 0;
}

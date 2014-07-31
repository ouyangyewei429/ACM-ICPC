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

const int maxn = 256;

char a[maxn];
int  T, alen, maxLen, i, bignum[maxn], rt=0;

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
        memset(a, 0, sizeof(0));
        memset(bignum, 0, sizeof(bignum));
        while ( cin >> a )
        {
            if ( !strcmp(a, "0") )  break;
            
            alen = strlen( a );
            for (i=0; i<alen; ++i)
                bignum[i] += (a[alen-i-1]-'0');
            
            maxLen = maxLen<alen ? alen:maxLen;
            for (i=0; i<=maxLen; ++i)
            {
                if ( bignum[i]>9 )
                    bignum[i+1]+=bignum[i]/10, bignum[i]%=10;
            }
            
            memset(a, 0, sizeof(a));
        }// blocks input

        maxLen = bignum[maxLen] ? maxLen:maxLen-1;
        for (i=maxLen; i>=0; --i)
            printf("%c", bignum[i]+'0');
        
        if ( T!=0 )
            printf("\n\n");
        else
            printf("\n");
    }// End of while
    
    //system("pause");
    return 0;
}

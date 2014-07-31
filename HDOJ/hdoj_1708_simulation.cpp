/*
PROG:   Fibonacci String
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

const int maxn = 60;

char a[35], b[35];
int  T, N, fib[maxn][27];

int main()
{
    scanf("%d", &T);
    getchar();
    while ( T-- )
    {        
        memset(fib, 0, sizeof(fib));
        
        scanf("%s %s %d", a, b, &N);
        for (int i=0; i<strlen(a); ++i)
            fib[0][a[i]-'a']++;
        for (int i=0; i<strlen(b); ++i)
            fib[1][b[i]-'a']++;
        
        for (int i=2; i<=N; ++i)
        {
            for (int j=0; j<26; ++j)
                fib[i][j] = fib[i-1][j]+fib[i-2][j];
        }// fib string
        
        for (int i=0; i<26; ++i)
            printf("%c:%d\n", i+'a', fib[N][i]);
        printf("\n");
    }// end of while
    
    return 0;
}

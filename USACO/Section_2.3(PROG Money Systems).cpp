/*
PROG:   money
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <memory.h>

int N, V, cc[30];
long long dp[10004];

int main()
{
    freopen("money.in", "r" ,stdin);
    freopen("money.out", "w", stdout);

    scanf("%d %d", &N, &V);
    for ( int i=1; i<=N; ++i )
        scanf("%d", &cc[i]);

    dp[0] = 1;
    for ( int i=1; i<=N; ++i )
    {
        for ( int j=0; j<=V; ++j )
        {
            if ( j>=cc[i] )
                dp[j] = dp[j]+dp[j-cc[i]];
        }
    }

    printf("%lld\n", dp[V]);
    
//    system("pause");
    return 0;
}
/*
    for ( int i=1; i<=N; ++i )  dp[i][0]=1;
    for ( int i=1; i<=N; ++i )
    {
        for ( int j=1; j<=V; ++j )
        {
            if ( j>=cc[i] ) dp[i][j] = dp[i-1][j]+dp[i][j-cc[i]];
            else    dp[i][j] = dp[i-1][j];
        }
    }
*/
/*
    for ( int i=1; i<=N; ++i )
    {
        for ( int j=0; j<=V; ++j )
            printf("%d ", dp[i][j]);
        printf("\n");
    }
*/

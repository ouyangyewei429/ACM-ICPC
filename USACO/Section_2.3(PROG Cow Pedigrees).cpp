/*
PROG:   nocows
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <memory.h>

int N, K, i, j, k;
long long dp[201][102];

int main()
{
    freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w", stdout);

    scanf("%d %d", &N, &K);
    for ( i=1; i<=K; ++i )  dp[1][i] = 1;
    for ( j=1; j<=K; ++j )
    {
        for ( i=1; i<=N; i+=2 )
        {
            for ( k=1; k<=i-2; ++k )
                dp[i][j] = ( dp[i][j]+dp[k][j-1]*dp[i-k-1][j-1] )%9901;
        }
    }// dp
    
    printf( "%lld\n", ( dp[N][K]-dp[N][K-1]+9901 )%9901 );
//    system("pause");
    return 0;
}

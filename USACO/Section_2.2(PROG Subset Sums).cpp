/*
PROG:   subset
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <memory.h>

int N, sum;
long long dp[40][800];

int main()
{
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
    
    scanf("%d", &N);
    sum = ( N*(N+1)/2 );
    if ( sum&1 )
        printf("0\n");
    else
    {
        sum >>= 1;
        dp[1][0]=dp[1][1]=1;
        for ( int i=2; i<=N; ++i )
        {
            for ( int j=0; j<=sum; ++j )
            {
                if ( j-i>=0 )
                    dp[i][j] = dp[i-1][j]+dp[i-1][j-i];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }// dp
        
        printf("%lld\n", dp[N][sum]/2);
    }    
    
 //   system("pause");
    return 0;
}

/*
PROG:   stamps
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
#include <iostream> 
#include <algorithm>
using namespace std;

namespace
{
    const int maxn = 2000000;
    
    int K, N, maxValue;
    int stValue[52], dp[maxn];  // dp：取得邮票面值 x 时需要的最少邮票张数 
}// Non Name Space

void ReadData()
{
    maxValue = -1;
    scanf("%d %d", &K, &N);
    for ( int i=0; i<N; ++i )
    {
        scanf("%d", &stValue[i]);
        if ( maxValue<stValue[i] )  maxValue = stValue[i];  // 记录邮票最大面值 
    }
}// ReadData

void Solve()
{
    int j, k;
    
    fill_n( dp, maxn, 1000 );
    for ( j=1, k=maxValue; k<=maxn; ++j, k+=maxValue )  dp[ k ] = j;
    
    if ( maxValue==1 )
    {
        printf("%d\n", K); 
    }
    else
    {
        dp[0] = 0;
        for ( k=1; k<=maxn; ++k )
        {
            if ( k%maxValue==0 )    continue;
            for ( j=0; j<N; ++j )
            {
                if ( k-stValue[j]>=0&&dp[ k-stValue[j] ]+1<dp[ k ] )
                    dp[ k ] = dp[ k-stValue[j] ]+1; 
            }
            if ( dp[k]>K )  break;
        }
        
        printf("%d\n", k-1);
    } 
}// Solve

int main()
{
    freopen("stamps.in", "r", stdin);
    freopen("stamps.out", "w", stdout);

    ReadData();
    Solve();
    
    //system("pause"); 
    return 0;
}

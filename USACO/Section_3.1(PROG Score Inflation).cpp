/*
PROG:   inflate
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
#include <algorithm>
using namespace std;

namespace
{
    int dp[1000004];
    int M, N, points, times;
}// Non Name Space

int Max( int x, int y )
{
    return ( x>y ? x:y );
}// Max

void Solve()
{
    scanf("%d %d", &M, &N);
    for ( int i=0; i<N; ++i )
    {
        scanf("%d %d", &points, &times);
        for ( int j=times; j<=M; ++j )
            dp[j] = Max( dp[j], dp[j-times]+points );
    }// End of for
    
    printf("%d\n", dp[M]);
    return ;
}// Solve

int main()
{
    freopen("inflate.in", "r", stdin);
    freopen("inflate.out", "w", stdout);
    
    Solve();
    
    return 0;
}

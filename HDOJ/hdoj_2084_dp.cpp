/*
PROG:   numtri
ID  :   ouyangyewei
LANG:   C
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define maxn 1004

int i, j, N, T, dp[maxn][maxn], mat[maxn][maxn];

int Max(int x, int y)
{
    return (x>y ? x:y);
}/* Max */

int main()
{/*
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);
*/
    scanf("%d", &T);
    while ( T-- )
    {
        scanf("%d", &N);
        for (i=0; i<N; ++i)
        {
            for (j=0; j<=i; ++j)
                scanf("%d", &mat[i][j]);
        }/* Input */
        
        for (i=0; i<N; ++i)
            dp[N-1][i] = mat[N-1][i];
        
        for (i=N-2; i>=0; --i)
        {
            for (j=0; j<=i; ++j)
                dp[i][j] = mat[i][j]+Max(dp[i+1][j], dp[i+1][j+1]);
        }/* dynamic programming  */
        
        printf("%d\n", dp[0][0]);
    }/* End of while */
    
    return 0;
}


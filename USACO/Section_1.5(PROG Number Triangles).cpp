/*
PROG:   numtri
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

const int maxn = 1004;
const int INF = 0x3F3F3F3F;

int N, result, mat[maxn][maxn];

void dfs(int x, int y, int depth, int sum)
{
    if (depth == N)
    {
        if (sum > result)
            result = sum;
        
        return ;
    }// destination
    
    dfs(x+1, y, depth+1, sum+mat[x+1][y]);      // down one step
    dfs(x+1, y+1, depth+1, sum+mat[x+1][y+1]);  // down and right one step
    
    return ;
}// dfs

int main()
{/*
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);
*/
    scanf("%d", &N);
    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<=i; ++j)
            scanf("%d", &mat[i][j]);
    }// Input
    
    result = -1;
    dfs( 0,0,0,mat[0][0] );  /* cur_x, cur_y, depth, sum */
    
    printf("%d\n", result);
    
    //system("pause");  //-------------------------------------------
    return 0;
}


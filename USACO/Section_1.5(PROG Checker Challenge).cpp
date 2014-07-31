/*
PROG:   checker
ID  :   ouyangyewei
LANG:   C++
*/
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <memory.h>

const int maxn = 15;

bool hash[3][maxn<<2];
int  N, cnt, result, path[maxn];

void dfs(int row)
{
    if ( row == N )
    {
        ++result;
        if ( cnt < 3 )
        {
            ++cnt;
            for (int i=0; i<N; ++i)
                printf(i==0 ? "%d":" %d", path[i]);
            printf("\n");
        }
        
        return ;
    }// destination
    
    for (int col=0; col<N; ++col)
    {
        if (!hash[0][col] && !hash[1][row-col+N]
            && !hash[2][row+col])
        {
            hash[0][col] = true, hash[2][row+col] = true;
            hash[1][row-col+N] = true;
            
            path[row] = col+1;
            dfs( row+1 );
            
            hash[0][col] = false, hash[2][row+col] = false;
            hash[1][row-col+N] = false;
        }
    }// Main Process
    
    return ;
}// dfs

int main()
{
    freopen("checker.in", "r", stdin);
    freopen("checker.out", "w", stdout);

    scanf("%d", &N);
    memset(hash, false, sizeof(hash));
    
    cnt=0, result=0;
    dfs( 0 );  /* row */
    printf("%d\n", result);
    
    //system("pause");
    return 0;
}

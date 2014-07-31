/*
PROG:   Nª ∫ÛŒ Ã‚
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <algorithm>
using namespace std;

int  N, cnt;
bool hash[3][25];

void dfs(int row)
{
    if (row == N)
    {
        ++cnt;
        return ;
    }// destination
    
    for (int col=0; col<N; ++col)
    {
        if (!hash[0][col] && !hash[1][row-col+N]
            && !hash[2][row+col])
        {
            hash[0][col]=true, hash[1][row-col+N]=true;
            hash[2][row+col]=true;
            
            dfs( row+1 );
            
            hash[0][col]=false, hash[1][row-col+N]=false;
            hash[2][row+col]=false;
        }
    }// Main Process
}// dfs

int main()
{
    while (~scanf("%d", &N), N!=0)
    {
        memset(hash, false, sizeof(hash));
        
        cnt = 0;
        dfs( 0 );
        
        printf("%d\n", cnt);
    }// End of while
    
    return 0;
}

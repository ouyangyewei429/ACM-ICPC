/*
PROG:   zerosum
ID  :   ouyangyewei
LANG:   C++
*/
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
#include <algorithm>
using namespace std;

int  N, num[10];
char cc[12];

void dfs( int cnt, int ans, int st, int k )
{
    if ( cnt==N && ans==0 )
    {
        printf("1");
        for ( int j=0; j<N-1; ++j )
            printf("%c%d", cc[j], num[j]);
        printf("\n");
        
        return ;
    }// destination
    
    for ( int i=st; i<=N; ++i )
    {
        cc[k] = '+', num[k] = i;
        dfs( cnt+1, ans+i, i+1, k+1 );
        
        cc[k] = '-', num[k] = i;
        dfs( cnt+1, ans-i, i+1, k+1 );
        
        if ( cc[k-1]!=' ' )
        {
            cc[k] = ' ', num[k] = i;
            if ( ans==1 || cc[k-1]=='+' ) dfs( cnt+1, ans-num[k-1]+num[k-1]*10+i, i+1, k+1 );
            if ( ans==1 || cc[k-1]=='-' ) dfs( cnt+1, ans+num[k-1]-num[k-1]*10-i, i+1, k+1 );
        }
    }// Main Process
    
    return ;
}// dfs

int main()
{/*
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);
*/
    scanf("%d", &N);
    dfs( 1, 1, 2, 0 );  /* count, result, start_position, index_of_path */
    
    system("pause");
    return 0;
}

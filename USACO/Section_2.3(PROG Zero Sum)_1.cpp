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

void dfs( int cnt, int sum, int last, int st, int k )
{
    if ( cnt==N && sum==0 )
    {
        printf("1");
        for ( int j=0; j<N-1; ++j ) printf("%c%d", cc[j], num[j]);
        printf("\n");
        
        return ;
    }// destination
    
    for ( int i=st; i<=N; ++i )
    {
        // Merge
        cc[k] = ' ', num[k] = i;
        if ( last>0 )   dfs( cnt+1, sum-last+last*10+i, last*10+i, i+1, k+1 );
        else    dfs( cnt+1, sum+(0-last)-(0-last)*10-i, -i-last*10, i+1, k+1 );
        
        // plus
        cc[k] = '+', num[k] = i;
        dfs( cnt+1, sum+i, i, i+1, k+1 );
        
        // sub
        cc[k] = '-', num[k] = i;
        dfs( cnt+1, sum-i, 0-i, i+1, k+1 );
    }// Main Process
    
    return ;
}// dfs

int main()
{
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);

    scanf("%d", &N);
    dfs( 1, 1, 1, 2, 0 );  /* counter, result, last_number, start_position, index_of_path */
    
//    system("pause");
    return 0;
}
/*
7
1+2-3+4-5-6+7
1+2-3-4+5+6-7
1-2 3+4+5+6+7
1-2 3-4 5+6 7
1-2+3+4-5+6-7
1-2-3-4-5+6+7

5
1 2-3-4-5
*/

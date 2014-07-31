/*
PROG:   concom
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
#include <algorithm>
using namespace std;

bool con[104], hash[104];
int  M, N=-1, sum[104], owns[104][104]={0};

void dfs( int k )
{
    if ( hash[ k ] )    return ;
    
    hash[ k ] = true;
    for ( int i=1; i<=N; ++i )
    {
        if ( k==i ) continue;
        
        sum[ i ] += owns[k][i];
        if ( sum[ i ]>=50 )
        {
            con[ i ] = true;
            dfs( i );
        }
    }// Main Process
    
    return ;
}// dfs

int main()
{
    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);

    int i, j, a, b, c;
    scanf("%d", &M);
    for ( i=1; i<=M; ++i )
    {
        scanf("%d %d %d", &a, &b, &c);
        if ( a>N )  N = a;
        if ( b>N )  N = b;
        owns[ a ][ b ] = c;
    }// creat a graph
    
    for ( i=1; i<=N; ++i )
    {
        fill_n( sum+1, N, 0 );
        fill_n( con+1, N, false );
        fill_n( hash+1, N, false );
        
        dfs( i );
        for ( j=1; j<=N; ++j )
        {
            if ( i!=j && con[j] )
                printf("%d %d\n", i, j);
        }// company j
    }// company i
    
//    system("pause");
    return 0;
}
/*
6 
1 2 30 
2 3 52 
3 4 51 
4 5 70 
5 4 20
4 3 20

2 3
2 4
2 5
3 4
3 5
4 5
------------------

7 
2 3 25 
1 4 36 
4 5 63 
2 1 48 
3 4 30 
4 2 52 
5 3 30

4 2
4 3
4 5

*/

/*
PROG:   concom
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>

bool used[104]={false}, hash[104]={false};
int  M, N=-1, sum, owns[104][104]={0};

bool dfs( int x, int y )
{
    if ( sum>=50 || owns[x][y]>=50 )
        return true;
    
    for ( int k=1; k<=N; ++k )
    {
        if ( hash[k] && x!=k && y!=k && owns[x][k]>=50 )
        {
            sum += owns[k][y];
            //used[k] = true;
            if ( dfs( k, y ) )  return true;
            //used[k] = false;
        }
    }// 
    
    return false;
}// dfs

int main()
{/*
    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);
*/
    int i, j, a, b, c;
    scanf("%d", &M);
    for ( i=1; i<=M; ++i )
    {
        scanf("%d %d %d", &a, &b, &c);
        if ( a>N )  N = a;
        if ( b>N )  N = b;
        owns[ a ][ b ] = c;
        hash[a] = hash[b] = true;
    }// creat a graph
    
    for ( i=1; i<=N; ++i )
    {
        for ( j=1; j<=N; ++j )
        {
            if ( i==j || !hash[i] || !hash[j] ) continue;
            if ( owns[ i ][ j ]>=50 )
                printf("%d %d\n", i, j);
            else
            {
                sum = 0;
                //used[i]=used[j]=true;
                if ( dfs( i, j ) )  printf("%d %d\n", i, j);
                //used[i]=used[j]=false;
            }
        }// company j
    }// company i
    
    system("pause");
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
------------------


*/

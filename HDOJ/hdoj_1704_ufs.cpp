/*
PROG:   Rank
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define DEBUG 0
#define maxn  504

int T, N, M, cnt, i, j, a, b, nodes[maxn];

int FindSet(int k)
{
    while ( k!=nodes[k] )
        k = nodes[k];
    
    return k;
}/* FindSet */

void Merge(int x, int y)
{
    int r1 = FindSet( x );
    int r2 = FindSet( y );
    if ( r1 == r2 )
        return ;
    
    if (r1 < r2)
        nodes[r2] = nodes[r1];
    else
        nodes[r1] = nodes[r2];
    
    return ;
}/* Merge */

int main()
{
#if DEBUG
    freopen("E:\\hdoj_1704.txt", "r", stdin);
    freopen("E:\\hdoj_1704_ans.txt", "w", stdout);
#endif    

    scanf("%d", &T);
    while ( T-- )
    {
        scanf("%d %d", &N, &M);
        for (i=0; i<=N; ++i)
            nodes[i] = i;
        
        for (i=1; i<=M; ++i)
        {
            scanf("%d %d", &a, &b);
            Merge( a,b );
        }/* Merge */
    
        cnt = 0;
        for (i=1; i<=N; ++i)
        {
            for (j=i+1; j<=N; ++j)
            {
                if ( FindSet(i)!=FindSet(j) )
                    ++cnt;
            }
        }/* counting */
        
        printf("%d\n", cnt);
    }/* End of while */
    
    return 0;
}

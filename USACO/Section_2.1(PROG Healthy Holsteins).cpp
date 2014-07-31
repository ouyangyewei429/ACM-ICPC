/*
PROG:   holstein
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>

const int INF = 0x3f3f3f3f;

int N, G, minValue, steps=0, vit[20]={0};
int sum[20]={0}, mark[10024]={0}, path[10024]={0}, feed[30][20]={0};

int CanTakeIt()
{
    for (int i=0; i<N; ++i)
    {
        if ( sum[i]<vit[i] )
            return 0;
    }// End of for
    
    return 1;
}// CanTakeIt

void Copy_Path()
{
    for (int i=0; i<G; ++i)
        path[i] = mark[i];
    
    return ;
}// Copy_Path

void TakeTheFeed(int k)
{
    ++steps;
    for (int i=0; i<N; ++i)
        sum[i] += feed[k][i];
    
    return ;
}// TakeTheFeed

void TakeOutTheFeed(int k)
{
    --steps;
    for (int i=0; i<N; ++i)
        sum[i] -= feed[k][i];
    
    return ;
}// TakeOutTheFeed

void dfs(int feedNums)
{
    if ( CanTakeIt() && minValue>steps )
    {
        minValue = steps;
        Copy_Path();
        
        return ;
    }// destination
    if ( feedNums >= G )
        return ;
    
    mark[ feedNums ] = 1;
    TakeTheFeed( feedNums );
    dfs( feedNums+1 );
    
    mark[ feedNums ] = 0;
    TakeOutTheFeed( feedNums );
    dfs( feedNums+1 );
    
    return ;
}// dfs 

int main()
{
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);

    scanf("%d", &N);
    for (int i=0; i<N; ++i)
        scanf("%d", &vit[i]);
        
    scanf("%d", &G);
    for (int i=0; i<G; ++i)
    {
        for (int j=0; j<N; ++j)
            scanf("%d", &feed[i][j]);
    }// Input
    
    minValue = INF;
//    TakeTheFeed( 0 );
    dfs( 0 ); /* feedNums */
/*
    minValue = INF;
    TakeOutTheFeed( 0 );
    dfs( 0, 0 );
*/
    int cnt = 0;
    printf("%d", minValue);
    for (int i=0; cnt<minValue; ++i)
    {
        if ( path[i] )
        {
            ++cnt;
            printf(" %d", i+1);
        }
    }
    printf("\n");
    
//    system("pause");
    return 0;
}

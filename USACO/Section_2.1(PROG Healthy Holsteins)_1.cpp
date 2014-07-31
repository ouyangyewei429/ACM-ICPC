/*
PROG:   holstein
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>

const int INF = 0x3F3F3F3F;

int N, G, minSteps, vit[28]={0}, feed[18][28]={0};
int sum[18]={0}, mark[18]={0}, path[18]={0};

bool CanTakeIt()
{
    for (int i=1; i<=N; ++i)
    {
        if ( sum[i]<vit[i] )
            return false;
    }// 
    
    return true;
}// CanTakeIt

void dfs(int feedNums, int steps)
{
    if ( CanTakeIt() )
    {
        if ( steps<minSteps )
        {
            minSteps = steps;
            for (int i=0; i<minSteps; ++i)
                path[i] = mark[i];
        }    
        return ;
    }// destination
    if ( feedNums > G )    return ;
    
    mark[ steps ] = feedNums;
    for (int i=1; i<=N; ++i)
        sum[i] += feed[feedNums][i];
    dfs( feedNums+1, steps+1 );
    
    mark[ steps ] = 0;
    for (int i=1; i<=N; ++i)
        sum[i] -= feed[feedNums][i];
    dfs( feedNums+1, steps );
    
    return ;
}// dfs

int main()
{
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);

    scanf("%d", &N);
    for (int i=1; i<=N; ++i)
        scanf("%d", &vit[i]);
    
    scanf("%d", &G);
    for (int i=1; i<=G; ++i)
    {
        for (int j=1; j<=N; ++j)
            scanf("%d", &feed[i][j]);
    }// Input
    
    minSteps = INF;
    dfs( 1, 0 );    /* feedNums, steps */
    
    printf("%d", minSteps);

    for (int i=0; i<minSteps; ++i)
        printf(" %d", path[i]);
    printf("\n");

//    system("pause");
    return 0;
}

/*
PROG:   Minimum Transport Cost
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <memory.h>

const int maxn = 1010;
const int INF = 0x3F3F3F3F;

bool in[maxn];
int  N, ss, tt;
int  costs[maxn], tax[maxn], path[maxn], edge[maxn][maxn];

void dijkstra()
{
    int i, j, u, minValue;
    for (i=1; i<=N; ++i)
    {
        in[i] = false;
        costs[i] = edge[ss][i]+tax[i];
        if (edge[ss][i]<INF)
            path[i] = ss;
        else
            path[i] = -1;
    }// Init
    
    in[ss] = true;
    costs[ss] = 0, costs[tt] -= tax[tt];
    for (i=1; i<=N; ++i)
    {
        minValue = INF;
        for (j=1; j<=N; ++j)
        {
            if (!in[j] && minValue>costs[j])
                u=j, minValue=costs[j];
        }// Find the node which costs is minimum
        
        in[u] = true;
        for (j=1; j<=N; ++j)
        {
            if (!in[j] && edge[u][j]<INF)
            {
                if (j==tt && costs[j]>=costs[u]+edge[u][j])
                    path[j]=u, costs[j]=costs[u]+edge[u][j];
                else if (j!=tt && costs[j]>=costs[u]+edge[u][j]+tax[j])
                    path[j]=u, costs[j] = costs[u]+edge[u][j]+tax[j];
            }
        }// modify the costs table
    }// Main Process
}// dijkstra

void dfs(int src, int x)
{
    if (src != x)
        dfs(src, path[x]);
    
    if (x != tt)
        printf("%d-->", x);
    
    return ;
}// dfs

int main()
{
    int i, j;
    while (~scanf("%d", &N), N!=0)
    {
        for (i=1; i<=N; ++i)
        {
            for (j=1; j<=N; ++j)
                scanf("%d", &edge[i][j]);
        }
        for (i=0; i<=N; ++i)
        {
            for (j=0; j<=N; ++j)
            {
                if (i==0 || j==0 || edge[i][j]<0)
                    edge[i][j] = INF;
            }
        }// preprocess
        for (i=1; i<=N; ++i)
            scanf("%d", &tax[i]);
        
        while (~scanf("%d %d", &ss, &tt), ss+tt!=-2)
        {
            printf("From %d to %d :\n", ss, tt);
            
            if (ss != tt)
            {
                dijkstra();
                printf("Path: ");
                dfs(ss, tt);
                printf("%d\nTotal cost : %d\n", tt, costs[tt]);
            }
            else
            {
                printf("Path: %d\n", ss);
                printf("Total cost : 0\n");
            }
            printf("\n");
        }// End of While
    }// End of While
    
    return 0;
}
/*
4
0 2 3 9
2 0 1 5
3 1 0 3
9 5 3 1
0 0 0 0
1 4

output: 1-->2-->3-->4
*/

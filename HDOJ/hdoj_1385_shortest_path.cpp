/*
PORG:   Minimum Transport Cost
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
#include <algorithm>
using namespace std;

const int maxn = 10010;
const int INF = 0x3F3F3F3F;

bool in[maxn];
int  N, w, ss, tt;
int  costs[maxn], tax[maxn], path[maxn], edge[maxn][maxn];

void dfs(int start, int x)
{
    if (path[x] != start)
        dfs(start, path[x]);
    
    if (x != tt)
    {
        //costs += tax[x];
        printf("%d-->", x);
    }
        
    return ;
}// dfs

void dijkstra()
{
    int i, j, u, minValue;
    for (i=1; i<=N; ++i)
    {
        costs[i] = tax[i]+edge[ss][i];
        if (edge[ss][i] < INF)
            path[i] = ss; // record the path
        else
            path[i] = -1;
    }// Init
    
    costs[ss]=0, in[ss]=true;
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
            if (!in[j] && dist[j]<INF && costs[j]>dist[u]+edge[u][j])
                path[j]=u, dist[j]=dist[u]+edge[u][j];
        }
    }// Main process
}// dijkstra

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
        
        // dijkstra
        while (~scanf("%d %d", &ss, &tt), ss+tt!=-2)
        {
            memset(in, false, sizeof(in));
            printf("From %d to %d :\n", ss, tt);
            dijkstra();
            
            costs = dist[tt];
            printf("Path: %d-->", ss);
            dfs(ss, tt);
            printf("%d\nTotal cost : %d\n", tt, costs);
        }
    }// End of While
    
    return 0;
}

/*
PROG:   一个人的旅行
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

const int maxn = 3004;
const int INF = 0x3F3F3F3F;

bool in[maxn];
int  T, S, D, N, lowcost;
int  ss[maxn], tt[maxn], dist[maxn], edge[maxn][maxn];

void dijkstra(int st)
{
    int i, j, u, minValue;
    for (i=1; i<=N; ++i)
        dist[i] = edge[st][i];
    
    dist[st]=0, in[st]=true;
    for (i=1; i<=N; ++i)
    {
        minValue = INF;
        for (j=1; j<=N; ++j)
        {
            if (!in[j] && minValue>dist[j])
                u=j, minValue=dist[j];
        }// Find the minimum
        
        in[u] = true;
        for (j=1; j<=N; ++j)
        {
            if (!in[j] && edge[u][j]<INF && dist[j]>dist[u]+edge[u][j])
                dist[j] = dist[u]+edge[u][j];
        }// modify the distance table
    }// Main process
}// dijkstra

int main()
{
    int i, j, u, v, w;
    while (~scanf("%d %d %d", &T, &S, &D))
    {
        memset(edge, INF, sizeof(edge));
        for (i=1, N=-1; i<=T; ++i)
        {
            scanf("%d %d %d", &u, &v, &w);
            edge[u][v] = edge[v][u] = w;
            if (u>v && u>N)
                N = u;
            else if (v>u && v>N)
                N = v;
        }// input
        for (i=1; i<=S; ++i)
        {
            scanf("%d", &ss[i]);
        }// preprocess
        for (i=1; i<=D; ++i)
        {
            scanf("%d", &tt[i]);
        }// input
        
        for (i=1, lowcost=INF; i<=S; ++i)
        {
            memset(in, false, (N+2)*sizeof(bool));
            dijkstra(ss[i]);
            for (j=1; j<=D; ++j)
            {
                //-----------------------------------
                //printf("-->%d\n", dist[tt[j]]);
                //------------------------------------
                
                if (lowcost > dist[tt[j]])
                    lowcost = dist[tt[j]];
            }// destination
            
            //-----------------------------
            //printf("--------------------------\n");
            //-----------------------------
            
        }// source point
        
        printf("%d\n", lowcost);
    }// End of While
    
    return 0;
}

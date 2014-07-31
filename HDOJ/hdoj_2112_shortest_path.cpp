/*
PROG:   HDU Today
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define DEBUG 0

const int MAXN_NODE = 10004;
const int MAXN_EDGE = 20010;
const int INF = 0x3F3F3F3F;

int  N, M, cnt, dist[MAXN_NODE];
char ss[35], tt[35], start[35], dest[35], city[MAXN_NODE][35];
struct EDGE
{
    int u, v, w;
}edge[MAXN_EDGE];

int index(char tar[])
{
    int i;
    for (i=0; i<N; ++i)
    {
        if (!strcmp(city[i], tar))
            return i;
    }
    
    strcpy(city[N++], tar);
    return i;
}// index

void Bellman_Ford(int src)
{
    int i, k;
/*
    for (i=0; i<=N*2; ++i)
        dist[i] = INF;
*/
    memset(dist, INF, sizeof(dist));
    
    dist[src] = 0;
    for (k=1; k<N; ++k)
    {
        for (i=0; i<cnt; ++i)
        {
            if (dist[edge[i].u]<INF
            && dist[edge[i].u]+edge[i].w<dist[edge[i].v])
            {
                dist[edge[i].v] = dist[edge[i].u]+edge[i].w;
            }
        }
    }// Main Process
}// Bellman_Ford

int main()
{
#if DEBUG
    freopen("E:\\hdoj_2112.txt", "r", stdin);
    freopen("E:\\hdoj_2112_ans.txt", "w", stdout);
#endif

    int i, a, b, c;
    while (~scanf("%d", &M), M!=-1)
    {
        for (i=0; i<=M; ++i)
        {
            strcpy(city[i], "\0");
        }// Init

        //memset(city, 0, sizeof(city));
        
        getchar();
        scanf("%s %s", start, dest);
        for (i=0, N=0, cnt=0; i<M; ++i)
        {
            getchar();
            scanf("%s %s %d", ss, tt, &c);
            a = index(ss), b = index(tt);
            edge[cnt].u=a, edge[cnt].v=b, edge[cnt].w=c;
            ++cnt;
            edge[cnt].u=b, edge[cnt].v=a, edge[cnt].w=c;
            ++cnt;
        }// preprocess
        
        a=index(start);
        b=index(dest);
        
        Bellman_Ford( a );
        
        if (dist[b] < INF)
            printf("%d\n", dist[b]);
        else
            printf("-1\n");
    }// end of while
    
    return 0;
}

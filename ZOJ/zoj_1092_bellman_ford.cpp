/*
PROG:   Arbitrage
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

//#define onlinejudge

const int maxn = 32;

int    N, M, cas=1;
double dist[maxn];
char   name[maxn][20], a[20], b[20];
struct EDGE
{
    int u, v;
    double w;
}edge[maxn*maxn];

void read_info()
{
    int i, j, k;
    double r;
    
    getchar();
    for (i=0; i<N; ++i)
        scanf("%s", name[i]);
    
    scanf("%d", &M);
    for (i=0; i<M; ++i)
    {
        getchar();
        scanf("%s %lf %s", a, &r, b);
        
        for (j=0; strcmp(a, name[j]); ++j)
        ;
        for (k=0; strcmp(b, name[k]); ++k)
        ;
        
        edge[i].u=j, edge[i].v=k, edge[i].w=r;
    }// preprocess
}// read_info

bool Bellman_Ford(int src)
{
    int i, k;
    
    memset(dist, 0, sizeof(dist));
    dist[src] = 1;
    for (k=1; k<=N; ++k)
    {
        for (i=0; i<M; ++i)
        {
            if (dist[edge[i].u]*edge[i].w > dist[edge[i].v])
            {
                dist[edge[i].v] = dist[edge[i].u]*edge[i].w;
            }
        }// end of for
    }// end of for
    
    if (dist[src] > 1.0)
        return true;
    else
        return false;
}// Bellman_Ford

int main()
{
#ifdef onlinejudge
    freopen("E:\\zoj_1092.txt", "r", stdin);
    freopen("E:\\zoj_1092_ans.txt", "w", stdout);
#endif

    int i, flag;
    while (~scanf("%d", &N), N!=0)
    {
        read_info();
        for (i=0, flag=0; i<N; ++i)
        {
            if ( Bellman_Ford( i ) )
            {
                flag = 1;
                break;
            }
        }// end of for
        if (flag)
            printf("Case %d: Yes\n", cas++);
        else
            printf("Case %d: No\n", cas++);
    }// End of while
    
    return 0;
}

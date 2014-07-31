/*
PROG:   一个人的旅行
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

const int maxn = 1204;
const int INF = 0x3F3F3F3F;

bool st[maxn], et[maxn];
int  T, S, D, N, lowcost;
int  dist[maxn][maxn], edge[maxn][maxn];

void Floyd()
{
    int i, j, k;
    for (i=1; i<=N; ++i)
    {
        for (j=1; j<=N; ++j)
            dist[i][j] = (i!=j) ? edge[i][j]:0;
    }// preprocess
    
    lowcost = INF;
    for (k=1; k<=N; ++k)
    {
        for (i=1; i<=N; ++i)
        {
            if (dist[i][k] != INF)
            {
                for (j=1; j<=N; ++j)
                {
                    if (k==i || k==j)   continue;
                    if (dist[i][k]+dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k]+dist[k][j];
                        
                    if (st[i] && et[j] && lowcost>dist[i][j])
                        lowcost = dist[i][j];
                }
            }// if road i is access to road k
        }
    }// Main Process
}// Floyd

int main()
{
    int i, j, a, b, c, ss, tt;
    while (~scanf("%d %d %d", &T, &S, &D))
    {
        memset(edge, INF, sizeof(edge));
        memset(dist, INF, sizeof(dist));
        
        N = -1;
        for (i=1; i<=T; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            edge[a][b] = edge[b][a] = c;
            if (a>b && a>N)
                N = a;
            else if (b>a && b>N)
                N = b;
        }// Input
            
        memset(st, false, sizeof(st));
        memset(et, false, sizeof(et));
        for (i=1; i<=S; ++i)
        {
            scanf("%d", &ss);
            st[ss] = true;
        }
        for (j=1; j<=D; ++j)
        {
            scanf("%d", &tt);
            et[tt] = true;
        }
        
        Floyd();
        printf("%d\n", lowcost);
    }// end of while 
    
    return 0;
}

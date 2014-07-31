/*
PROG:   一个人的旅行
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

const int maxn = 1004;
const int INF = 0x3F3F3F3F;

bool ss[maxn], tt[maxn];
int  T, S, D, N;
int  dist[maxn][maxn], edge[maxn][maxn];

int Floyd()
{
    int i, j, k, lowcost=INF;
    for (i=1; i<=N; ++i)
    {
        for (j=1; j<=N; ++j)
            dist[i][j] = edge[i][j];
    }// preprocess
    
    for (k=1; k<=N; ++k)
    {
        for (i=1; i<=N; ++i)
        {
            for (j=1; j<=N; ++j)
            {
     //           if (k==i || k==j)   continue;
                if (dist[i][k]+dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k]+dist[k][j];
                    
                if (ss[i] && tt[j])
                    lowcost = lowcost>dist[i][j] ? dist[i][j]:lowcost;
            }
        }
    }// Main Process
    
    return lowcost;
}// Floyd

int main()
{
    int i, j, a, b, c, st, et;
    while (~scanf("%d %d %d", &T, &S, &D))
    {
        memset(ss, false, sizeof(ss));
        memset(tt, false, sizeof(tt));
        memset(edge, INF, sizeof(edge));
        //memset(dist, INF, sizeof(dist));
        
        N = -1;
        for (i=1; i<=T; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            if (c < edge[a][b])
                edge[a][b] = edge[b][a] = c;
            if (a>b && a>N)
                N = a;
            else if (b>a && b>N)
                N = b;
        }// Input
        for (i=1; i<=S; ++i)
        {
            scanf("%d", &st);
            ss[st] = true;
        }
        for (i=1; i<=D; ++i)
        {
            scanf("%d", &et);
            tt[et] = true;
        }// preprocess
        
        printf("%d\n", Floyd());
    }// end of while
    
    return 0;
}

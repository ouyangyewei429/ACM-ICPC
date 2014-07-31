/*
PROG:   Heavy Cargo
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>

const int maxn = 204;
const int INF = 0x3F3F3F3F;

int  N, M, cnt, cas=1, dist[maxn][maxn], edge[maxn][maxn];
char start[35], dest[35], city[maxn][35];

int index(char str[])
{
    int i;
    for (i=0; i<cnt; ++i)
    {
        if (!strcmp(str, city[i]))
            return i;
    }
    
    strcpy(city[cnt++], str);
    return i;
}// Read_Data

int Min(int x, int y)
{
    return (x<y ? x:y);
}// Min

int Max(int x, int y)
{
    return (x>y ? x:y);
}// Max

void Floyd()
{
    int i, j, k;
    for (i=0; i<N; ++i)
    {
        for (j=0; j<N; ++j)
            dist[i][j] = edge[i][j];
    }// preprocess
    
    for (k=0; k<N; ++k)
    {
        for (i=0; i<N; ++i)
        {
            for (j=0; j<N; ++j)
            {
                if (k==i || k==j)   continue;
                dist[i][j] = Max(dist[i][j], Min(dist[i][k], dist[k][j]));
            }
        }
    }// Main Process
}// Floyd

int main()
{
    int i, j, a, b, limit;
    while (~scanf("%d %d", &N, &M), N+M!=0)
    {
        //memset(city, 0, sizeof(city));
        for (i=0; i<=N; ++i)
        {
            strcpy(city[i], "\0");
            for (j=0; j<=N; ++j)
                edge[i][j] = (i!=j) ? -1:INF;
        }// Init
        
        cnt = 0;
        for (i=0; i<M; ++i)
        {
            scanf("%s %s %d", start, dest, &limit);
            a = index(start), b = index(dest);
            edge[a][b] = edge[b][a] = limit;
        }// creat the Adjacent Matrix
        
        Floyd();
        scanf("%s %s", &start, &dest);
        i = index(start), j = index(dest);
        
        printf("Scenario #%d\n", cas++);
        printf("%d tons\n\n", dist[i][j]);
    }// end of while
    
    return 0;
}

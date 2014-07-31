/*
PROG:   Seaside
ID  :   ouyangyewei
LANG:   C++
*/
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
using namespace std;

const int MAXN = 12;
const int INF = 0x3F3F3F3F;

bool inq[MAXN];
int  N, M, p, cnt, temp, lowcost;
int  ss[MAXN], edge[MAXN][MAXN], dist[MAXN];

int spfa(int src)
{
    int u;
    queue <int> q;
    
    inq[src]=true, dist[src]=0;
    q.push( src );
    while ( !q.empty() )
    {
        u = q.front();
        q.pop();
        inq[u] = false;
        
        for (int i=0; i<N; ++i)
        {
            if (dist[u]+edge[u][i] < dist[i])
            {
                dist[i] = dist[u]+edge[u][i];
                if ( !inq[i] )
                    inq[i]=true, q.push(i);
            }
        }// End of for
    }// End of while
    
    return dist[0];
}// spfa

int main()
{
    int tt, w;
    while (~scanf("%d", &N))
    {
        memset(edge, INF, sizeof(edge));
        //memset(edge, 0, sizeof(edge));  //---------------------
        
        cnt = 0;
        for (int i=0; i<N; ++i)
        {
            scanf("%d %d", &M, &p);
            if ( p==1 ) ss[cnt++] = i;
            for (int j=0; j<M; ++j)
            {
                scanf("%d %d", &tt, &w);
                edge[tt][i] = w;
            }// M lines
        }// N blocks
        
        /*
        printf("---------------------\n");
        for (int i=0; i<cnt; ++i)   printf("%d ", ss[i]);
        printf("\n------------------\n");
        for (int i=0; i<N; ++i)
        {
            for (int j=0; j<N; ++j)
                printf("%3d ", edge[i][j]);
            printf("\n");
        }
        printf("-----------------------\n");
        */
      
        lowcost = INF;
        for (int i=0; i<cnt; ++i)
        {
            memset(inq, false, sizeof(inq));
            memset(dist, INF, sizeof(dist));

            temp = spfa( ss[i] );
            if ( lowcost>temp )
                lowcost = temp;
        }// Find the minimum
        
        printf("%d\n", lowcost);

    }// end of while
    
    return 0;
}

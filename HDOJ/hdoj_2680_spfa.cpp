/*
PROG:   Choose the best route
ID  :   ouyangyewei
LANG:   C++
*/
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
using namespace std;

const int MAXN_NODE = 1004;
const int MAXN_EDGE = 20004;
const int INF = 0x3F3F3F3F;

bool inq[MAXN_NODE];
int  N, M, K, ss, tt, lowcost, dist[MAXN_NODE];
struct ArcNode
{
    int v, w;
    ArcNode *next;
}*List[MAXN_NODE];

void spfa(int src)
{
    int u, i;
    queue <int> q;
    ArcNode *temp = NULL;
    
    dist[src]=0, inq[src]=true;
    
    q.push(src);
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        inq[u] = false;
        
        temp = List[u];
        while (temp != NULL)
        {
            if (dist[u]+temp->w < dist[temp->v])
            {
                dist[temp->v] = dist[u]+temp->w;
                if (!inq[temp->v])
                    inq[temp->v]=true, q.push(temp->v);
            }
            
            temp = temp->next;
        }// end of while
    }// Main Process
}// spfa

int main()
{
    ArcNode *temp = NULL;
    int i, j, a, b, c;
    while (~scanf("%d %d %d", &N, &M, &ss))
    {
        for (i=1; i<=N; ++i)
        {
            inq[i] = false;
            dist[i] = INF;
            List[i] = NULL;
        }// Init
        
        for (i=1; i<=M; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            
            temp = new ArcNode;
            temp->v=a, temp->w=c;
            temp->next=List[b], List[b]=temp;
        }// creat the adjacent table
        
        spfa( ss );
        
        lowcost = INF;
        scanf("%d", &K);
        for (i=1; i<=K; ++i)
        {
            scanf("%d", &tt);
            if (dist[tt]!=INF && lowcost>dist[tt])
                lowcost = dist[tt];
        }// Find the lowcost
        
        if (lowcost < INF)
            printf("%d\n", lowcost);
        else
            printf("-1\n");
    }// end of while
    
    return 0;
}

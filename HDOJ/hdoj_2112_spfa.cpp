/*
PROG:   HDU Today
ID  :   ouyangyewei
LANG:   C++
*/
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
using namespace std;

#define DEBUG 1

const int maxn = 10010;
const int INF = 0x3F3F3F3F;

bool inq[maxn];
int  N, M, dist[maxn];
char ss[35], tt[35], start[35], dest[35], city[maxn][35];
struct ArcNode
{
    int v, w;
    ArcNode *next;
}*List[maxn];

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
        }
    }// end of while
}// Bellman_Ford

int main()
{
#if DEBUG
    freopen("E:\\hdoj_2112.txt", "r", stdin);
    freopen("E:\\hdoj_2112_ans.txt", "w", stdout);
#endif

    int i, a, b, c;
    ArcNode *temp=NULL;
    
    while (~scanf("%d", &M), M!=-1)
    {
        for (i=0; i<=M; ++i)
        {
            strcpy(city[i], "\0");
            List[i] = NULL;
            inq[i] = false;
            dist[i] = INF;
        }// Init
        
        getchar();
        scanf("%s %s", start, dest);
        for (i=0, N=0; i<M; ++i)
        {
            getchar();
            scanf("%s %s %d", ss, tt, &c);
            a = index(ss), b = index(tt);
            
            temp = new ArcNode;
            temp->v=b, temp->w=c;
            temp->next=List[a], List[a]=temp;
        }// preprocess
        
        a=index(start);
        b=index(dest);
        
        spfa( a );
        
        if (dist[b] < INF)
            printf("%d\n", dist[b]);
        else
            printf("-1\n");
    }// end of while
    
    return 0;
}

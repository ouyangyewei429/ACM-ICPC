/*
PORG:   Silver Cow Party
ID  :   ouyangyewei
LANG:   C++
*/
#include <queue>
#include <cstdio>
#include <cstdlib>
using namespace std;

//#define onlinejudge

const int maxn = 1004;
const int INF = 0x3F3F3F3F;

bool inq[maxn];
int  N, M, X, result, dist[maxn], sum[maxn];
struct ArcNode
{
    int v, w;
    ArcNode *next;
}*edge[maxn], *redge[maxn];

void Insert(int a, int b, int c)
{   
    // 构建正向图 
    ArcNode *pa = new ArcNode;
    pa->v=b, pa->w=c;
    pa->next=edge[a], edge[a]=pa;

    // 构建反向图
    ArcNode *pb = new ArcNode;
    pb->v=a, pb->w=c;
    pb->next=redge[b], redge[b]=pb;

    return ;
}// Insert

void spfa(int oper, int src)
{
    int i, u;
    queue <int> q;
    ArcNode *temp = NULL;
    
    for (i=1; i<=N; ++i)
        dist[i]=INF, inq[i]=false;
    
    dist[src]=0, inq[src]=true;
    q.push(src);
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        inq[u] = false;
        
        if (oper == 0)
            temp = redge[u];
        else
            temp = edge[u];

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
    }// end of while
}// spfa
/*
void display()
{
    printf("-------------------------\n");
    for (int i=1; i<=N; ++i)
        printf("%d ", dist[i]);
    printf("\n-----------------------\n");
}
*/
int main()
{
#ifdef onlinejudge
    freopen("E:\\poj_3268.txt", "r", stdin);
    freopen("E:\\poj_3268_ans.txt", "w", stdout);
#endif

    int i, a, b, c;
    while (~scanf("%d %d %d", &N, &M, &X))
    {
        for (i=1; i<=N; ++i)
        {
            sum[i] = 0;
            edge[i] = redge[i] = NULL;
        }// preprocess
            
        for (i=1; i<=M; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            Insert(a, b, c);
        }// Insert
        
        spfa(0, X);
        for (i=1; i<=N; ++i)
            sum[i] += dist[i];
        
//        display();  // debug-----------------------------------
        
        spfa(1, X);

//        display();  // debug-----------------------------------
        
        result = -1;
        for (i=1; i<=N; ++i)
        {
            sum[i] += dist[i];
            if (result < sum[i])
                result = sum[i];
        }// Find the Maximum costs
        
        printf("%d\n", result);
    }// end of while
    
    return 0;
}

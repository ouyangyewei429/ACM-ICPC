#include <queue>
#include <cstdio>
#include <memory.h>
using namespace std;

//#define onlinejudge

const int maxn = 1004;

char maze[maxn][maxn];
int  graph[maxn][maxn];
int  R, C, N, sx, sy, tx, ty;
int  dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int  dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
struct Graph
{
    int x, y, t;
    
    bool operator < (const Graph &a) const
    {
        return a.t < t;
    }
};

void Init_Hash()
{
    for (int i=0; i<R; ++i)
    {
        for (int j=0; j<C; ++j)
            graph[i][j] = 0x3F3F3F3F;
    }
}// Init_Hash

bool IsOut(int x, int y)
{
    return (x<0 || y<0 || x>=R || y>=C);
}/* IsOut */
/***
void shiftdown(int k, int n)
{
    int son;
    struct Graph key = heap[k];
    
    for (; k<=n>>1; k=son)
    {
        son = k<<1;
        if (k!=n && heap[son].t<heap[son+1].t)
            son = son + 1;
        
        if (key.t > heap[son].t)
            heap[k] = heap[son];
        else
            break;
    }
    heap[k] = key;
}

void push(struct Graph son)
{    
    int p = ++len;
    
    while (p!=1 && heap[p>>1].t>son.t)
    {
        heap[p] = heap[p>>1];
        p >>= 1;
    }
    heap[p] = son;
}

void top(struct Graph &ret)
{
    ret = heap[1];
    heap[1] = heap[len];
    heap[len] = zer;
    
    shiftdown(1, --len);
}
****/
int bfs()
{
    priority_queue <Graph> q;
    struct Graph c, n;
    
    c.x = sx-1, c.y = sy-1;
    c.t = graph[sx-1][sy-1] = 0;
    
    q.push(c);
    while (!q.empty())
    {
        c = q.top();
        q.pop();
        
        //---------------------------------------
        //printf("%d # %d %d -> %c\n", c.t, c.x, c.y, maze[c.x][c.y]);
        
        if (c.x==tx-1 && c.y==ty-1)
            return graph[c.x][c.y];
        
        for (int i=0; i<8; ++i)
        {
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
            
            if (IsOut(n.x, n.y))
                continue;
            
            if (graph[n.x][n.y]>graph[c.x][c.y]+(i!=maze[c.x][c.y]-'0'))
            {
                graph[n.x][n.y] = graph[c.x][c.y]+(i!=maze[c.x][c.y]-'0');
                n.t = graph[n.x][n.y];
                q.push(n);
            }
        }
    }/* End of While */
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_2757.txt", "r", stdin);
    freopen("E:\\hdoj_2757_ans.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &R, &C))
    {
        for (int i=0; i<R; ++i)
            scanf("%s", maze[i]);
        
        scanf("%d", &N);
        for (int i=0; i<N; ++i)
        {
            Init_Hash();
            scanf("%d %d %d %d", &sx, &sy, &tx, &ty);
            printf("%d\n", bfs());
        }
    }/* End of While */
    
    return 0;
}

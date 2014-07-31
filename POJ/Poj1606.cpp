#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define onlinejudge

int aNum, bNum, gNum;
int vis[1010][1010];

struct Node
{
    int a;
    int b;
    int op;
}mark[1010][1010], q[1000010];

struct parent
{
    int x;
    int y;
}prev[1010][1010];

void DFS(int x, int y)
{
    if (prev[x][y].x+prev[x][y].y != 0)
    {
        DFS(prev[x][y].x, prev[x][y].y);
    }/* End of If */
    
    switch (mark[x][y].op)
    {
        case 1: printf("fill A\n"); break;
        case 2: printf("fill B\n"); break;
        case 3: printf("empty A\n"); break;
        case 4: printf("empty B\n"); break;
        case 5: printf("pour A B\n"); break;
        case 6: printf("pour B A\n"); break;
    }
    
    return ;
}/* DFS */

void BFS()
{
    int front = -1;
    int rear = -1;
    struct Node cur, next;
    
    cur.a = 0;
    cur.b = 0;
    cur.op = 0;
    q[++rear] = cur;
    vis[cur.a][cur.b] = 1;
    
    while (front != rear)
    {
        cur = q[++front];
        if (cur.b == gNum)
        {
            DFS(cur.a, cur.b);
            
            printf("success\n");
            break;
        }
        
        /* OP 1: Fill(A) */
        next.a = aNum;
        next.b = cur.b;
        next.op = 1;
        if (!vis[next.a][next.b])
        {
            vis[next.a][next.b] = 1;
            mark[next.a][next.b].op = 1;
            prev[next.a][next.b].x = cur.a;
            prev[next.a][next.b].y = cur.b;
            q[++rear] = next;
        }
        
        /* OP 2: Fill(B) */
        next.a = cur.a;
        next.b = bNum;
        next.op = 2;
        if (!vis[next.a][next.b])
        {
            vis[next.a][next.b] = 1;
            mark[next.a][next.b].op = 2;
            prev[next.a][next.b].x = cur.a;
            prev[next.a][next.b].y = cur.b;
            q[++rear] = next;
        }
        
        /* OP 3: Empty(A) */
        next.a = 0;
        next.b = cur.b;
        next.op = 3;
        if (!vis[next.a][next.b])
        {
            vis[next.a][next.b] = 1;
            mark[next.a][next.b].op = 3;
            prev[next.a][next.b].x = cur.a;
            prev[next.a][next.b].y = cur.b;
            q[++rear] = next;
        }
        
        /* OP 4: Empty(B) */
        next.a = cur.a;
        next.b = 0;
        next.op = 4;
        if (!vis[next.a][next.b])
        {
            vis[next.a][next.b] = 1;
            mark[next.a][next.b].op = 4;
            prev[next.a][next.b].x = cur.a;
            prev[next.a][next.b].y = cur.b;
            q[++rear] = next;
        }
        
        /* OP 5: Pour(A, B) */
        next.b = (cur.a+cur.b)<bNum ? (cur.a+cur.b) : bNum;
        next.a = cur.a - (next.b - cur.b);
        next.op = 5;
        if (!vis[next.a][next.b])
        {
            vis[next.a][next.b] = 1;
            mark[next.a][next.b].op = 5;
            prev[next.a][next.b].x = cur.a;
            prev[next.a][next.b].y = cur.b;
            q[++rear] = next;
        }
        
        /* OP 6: Pour(B, A) */
        next.a = (cur.a+cur.b)<aNum ? (cur.a+cur.b) : aNum;
        next.b = cur.b - (next.a - cur.a);
        next.op = 6;
        if (!vis[next.a][next.b])
        {
            vis[next.a][next.b] = 1;
            mark[next.a][next.b].op = 6;
            prev[next.a][next.b].x = cur.a;
            prev[next.a][next.b].y = cur.b;
            q[++rear] = next;
        }
    }/* End of While */
}/* BFS */

int main()
{
#ifdef onlinejudge
    freopen("E:\\poj1606.txt", "r", stdin);
    freopen("E:\\poj1606(result).txt", "w", stdout);
#endif

    while (3 == scanf("%d %d %d", &aNum, &bNum, &gNum))
    {
        memset(vis, 0, sizeof(vis));
        memset(prev, 0, sizeof(prev));
        memset(mark, 0, sizeof(mark));
        memset(q, 0, sizeof(q));
        
        BFS();
    }/* End of While */
    
    return 0;
}

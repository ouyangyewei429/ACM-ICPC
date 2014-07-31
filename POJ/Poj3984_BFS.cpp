#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int vis[10][10] = {0};
int i, j, maze[10][10]={0};
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Node
{
    int x;
    int y;
}q[30]={0};

struct path
{
    int x;
    int y;
}prev[10][10]={0};

int IsInBound(int x, int y)
{
    if (x<0 || y<0 || x>=5 || y>=5)
        return 0;
    
    return 1;
}/* IsInBound */

void DFS(int x, int y)
{
    if (x+y != 0)
    {
        DFS(prev[x][y].x, prev[x][y].y);
    }/* End of If */
    
    printf("(%d, %d)\n", x, y);
    return ;
}/* DFS */

void BFS()
{
    int i;
    int sx = 0;
    int sy = 0;
    int tx = 4;
    int ty = 4;
    int front = -1;
    int rear = -1;
    struct Node cur, next;
    
    cur.x = sx;
    cur.y = sy;
    q[++rear] = cur;
    
    vis[cur.x][cur.y] = 1;
    while (front < rear)
    {
        cur = q[++front];
        if (cur.x==tx && cur.y==ty)
        {
            DFS(cur.x, cur.y);
            break;
        }/* End of If */
        
        for (i=0; i<4; ++i)
        {
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];
            if (!vis[next.x][next.y] && maze[next.x][next.y]==0
                && IsInBound(next.x, next.y))
            {
                vis[next.x][next.y] = 1;
                prev[next.x][next.y].x = cur.x;
                prev[next.x][next.y].y = cur.y;
                q[++rear] = next;
            }
        }/* End of For */
    }/* End of While */
}/* BFS */

int main()
{
    for (i=0; i<5; ++i)
    {
        for (j=0; j<5; ++j)
        {
            scanf("%d", &maze[i][j]);
        }
    }/* End of For */
    
    BFS();
    
    system("pause");
    return 0;
}

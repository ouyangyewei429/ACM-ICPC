#include <stdio.h>
#include <stdlib.h>

int vis[305][305], mat[305][305];
int dx[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[] = {-1, 1, 2, 2, 1, -1, -2, -2};
int casenum, nNum, sx, sy, tx, ty, i;

struct point
{
    int x, y;
}cur, next, q[90005]={0};

int IsInBound(int x, int y)
{
    return (x>=0 && y>=0 && x<nNum && y<nNum);
}/* IsInBound */

int Solve()
{
    int rear = -1;
    int front = -1;
    
    cur.x = sx;
    cur.y = sy;
    vis[sx][sy] = 1; /* 从起始位置开始的探索标记为 1 */ 
    q[++rear] = cur; /* 起始坐标入队 */ 
    
    next.x = tx;
    next.y = ty;
    vis[tx][ty] = 2;  /* 从终点位置开始的探索标记为 2 */ 
    q[++rear] = next; /* 终点坐标入队 */ 
    
    while (front < rear)
    {
        cur = q[++front]; /* 队首节点坐标出队 */
        
        for (i=0; i<8; ++i)
        {
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];
            
            if (!IsInBound(next.x, next.y))
                continue;
                
            if (!vis[next.x][next.y])
            {
                vis[next.x][next.y] = vis[cur.x][cur.y];     /* 设为与当前探索路径相同的标记 */
                mat[next.x][next.y] = mat[cur.x][cur.y] + 1; /* 记录步数 */ 
                q[++rear] = next; /* 当前合法坐标位置入队 */ 
            }
            else if (vis[cur.x][cur.y] != vis[next.x][next.y])
            {   /* 说明从起点出发的探索与从终点出发的探索重合 */ 
                return mat[cur.x][cur.y]+mat[next.x][next.y]+1;
            }
        }/* End of For */
    }/* End of While */
}/* Solve */

int main()
{
    scanf("%d", &casenum);
    while (casenum--)
    {
        memset(vis, 0, sizeof(vis));
        memset(mat, 0, sizeof(mat));
        
        scanf("%d", &nNum);
        scanf("%d %d", &sx, &sy);
        scanf("%d %d", &tx, &ty);
        
        if (sx==tx && sy==ty)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n", Solve());
        }    
    }/* End of While */
    
    return 0;
}

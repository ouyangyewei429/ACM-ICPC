#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define onlinejudge

int i, j, x, y, nNum, casenum;
int tx, ty, sx, sy, front, rear, newx, newy;
int qx[90010], qy[90010]; /* 设置坐标队列 */
int vis[310][310];        /* 设置访问数组 */ 
int dis[310][310];        /* 记录移动距离 */ 
int dx[] = {2, 2, 1, -1, -2, -2, -1, 1}; /* 定义(X, Y)可移动的8个方位X坐标 */ 
int dy[] = {1, -1, -2, -2, -1, 1, 2, 2}; /* 定义(X, Y)可移动的8个方位Y坐标 */

int main()
{
#ifdef onlinejudge
    freopen("E:\\poj1915.txt", "r", stdin);
    freopen("E:\\poj1915(result).txt", "w", stdout);
#endif

    scanf("%d", &casenum);
    while (casenum--)
    {
        scanf("%d", &nNum);
        scanf("%d %d", &sx, &sy);
        scanf("%d %d", &tx, &ty);
        
        /* vis, dis 数组清空 */ 
        memset(vis, 0, sizeof(vis));
        memset(dis, 0, sizeof(dis));
        
        /* 起始点入队 */ 
        front = rear = 0;
        qx[rear] = sx;
        qy[rear] = sy;
        ++rear;
        
        vis[sx][sy] = 1; /* 起点设置为已被访问 */ 
        while (front < rear)
        {
            /* 出队，获得队首坐标 */ 
            x = qx[front];
            y = qy[front];
            ++front;
            
            if (x==tx && y==ty)
            {   /* 走到出口，退出循环 */ 
                break;
            }
            
            for (i=0; i<8; ++i)
            {
                /* (X, y)移动范围内的8份方位 */ 
                newx = x + dx[i];
                newy = y + dy[i];
                if (!vis[newx][newy] && newx>=0 && newy>=0
                    && newx<nNum && newy<nNum)
                {   /* 可行的移动方位 */
                    vis[newx][newy] = 1;           /* 当前位置设置为已被访问过 */ 
                    dis[newx][newy] = dis[x][y]+1; /* 记录当前移动路径总的移动步数 */
                    
                    /* 当前新坐标入队 */ 
                    qx[rear] = newx;
                    qy[rear] = newy;
                    ++rear;
                }
            }
        }/* End of while */
        
        printf("%d\n", dis[tx][ty]);
    }/* End of While */
    
    return 0;
}

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define onlinejudge

char a, b;
int  i, front, rear;
int  sx, sy, tx, ty, x, y, newx, newy;
int  qx[70], qy[70], dis[10][10], vis[10][10];
int  dx[] = {2, 2, 1, -1, -2, -2, -1, 1}; /* 定义(X, Y)可移动的8个方位X坐标 */ 
int  dy[] = {1, -1, -2, -2, -1, 1, 2, 2}; /* 定义(X, Y)可移动的8个方位Y坐标 */

int main()
{
#ifdef onlinejudge
    freopen("E:\\poj2243.txt", "r", stdin);
    freopen("E:\\poj2243(result).txt", "w", stdout);
#endif

    while (~scanf("%c%d %c%d", &a, &sy, &b, &ty))
    {
        getchar(); /* 清除上次输入后的回车符 */ 
        /***
        printf("#%c%d %c%d#\n", a, sy, b, ty);
        ***/
        sx = a - 'a'+1;
        tx = b - 'a'+1;
        /*****
        printf("%d %d\n%d %d\n#\n", sx, sy, tx, ty);
        *****/
        if (sx==tx && sy==ty)
        {
            printf("To get from %c%d to %c%d takes 0 knight moves.\n", a, sy, b, ty);
        }/* End of If */
        else
        {
            /* 清空 vis，dis 数组 */
            memset(vis, 0, sizeof(vis));
            memset(dis, 0, sizeof(dis));
            
            /* 起点入队 */ 
            front = rear = 0;
            qx[rear] = sx;
            qy[rear] = sy;
            ++rear;
            
            vis[sx][sy] = 1;  /* 起点设置为已被访问 */ 
            //dis[sx][sy] = 0;  /* 预置dis */ 
            while (front < rear)
            {
                /* 队首坐标出列 */ 
                x = qx[front];
                y = qy[front];
                ++front;
                
                if (x==tx && y==ty)
                {   /* 到达终点 */ 
                    break;
                }
                
                for (i=0; i<8; ++i)
                {
                    /* 访问（x，y）可移动范围内的8个方位 */ 
                    newx = x + dx[i];
                    newy = y + dy[i];
                    if (!vis[newx][newy] && newx>=1 && newy>=1
                        && newx<=8 && newy<=8)
                    {
                        vis[newx][newy] = 1;  /* 当前方位设置为已被访问 */ 
                        dis[newx][newy] = dis[x][y]+1; /* 记录当前移动路径的移动次数 */
                        
                        /* 当前方位入队 */ 
                        qx[rear] = newx;
                        qy[rear] = newy;
                        ++rear;
                    }
                }
            }/* End of while */
            
            printf("To get from %c%d to %c%d takes %d knight moves.\n", a, sy, b, ty, dis[tx][ty]);
        }/* End of Else */
    }/* End of While */
    
    return 0;
}

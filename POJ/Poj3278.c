#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int nNum, kNum, x;
int front, rear;
int q[100010], dis[100010], vis[100010];

int main()
{
    while (2 == scanf("%d %d", &nNum, &kNum))
    {
        /* 清空整形数组 */ 
        memset(q, 0, sizeof(q));
        //memset(dis, 0, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        
        front = rear = -1;   /* 初置队列 */
        q[++rear] = nNum;    /* 起点入队 */
        dis[nNum] = 0;
        while (front != rear)
        {   /* 队列不为空时循环 */ 
            x = q[++front];
            if (x == kNum)
            {
                break;
            }
            
            vis[x] = 1; /* 设定为已被访问 */ 
            if (x>0 && vis[x-1]==0)
            {
                q[++rear] = x-1;
                dis[x-1] = dis[x]+1;
                vis[x-1] = 1;
            }
            if (x<100000 && vis[x+1]==0)
            {
                q[++rear] = x+1;
                dis[x+1] = dis[x]+1;
                vis[x+1] = 1;
            }
            if (x<=50000 && vis[x+x]==0)
            {
                q[++rear] = x+x;
                dis[x+x] = dis[x]+1;
                vis[x+x] = 1;
            }
            
        }/* End of while */
        
        printf("%d\n", dis[kNum]);
    }/* End of While */
    
    return 0;
}

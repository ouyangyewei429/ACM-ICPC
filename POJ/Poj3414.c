#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define onlinejudge

int aNum, bNum, cNum;

struct Node
{   /* 每种情况都视为一个节点 */ 
    int a;
    int b;
    int step;
}temp, ver, q[200];

struct father
{   /* 记录当前节点的相亲 */ 
    int prex;
    int prey;
}prev[110][110];
 
int vis[110][110];

void DFS(int x, int y)
{
    int px, py;
    
    if (prev[x][y].prex+prev[x][y].prey != 0)
    {   /* 返回起点的下一个顶点 */ 
        DFS(prev[x][y].prex, prev[x][y].prey);
    }

    /* 获得前一个顶点的x，y */ 
    px = prev[x][y].prex;
    py = prev[x][y].prey;
    
    /* OP 1: FILL(i) */
    if (px!=aNum && x==aNum && py==y)
    {
        printf("FILL(1)\n");
        return ;
    }
    
    /* OP 2: FILL(j) */
    if (py!=bNum && y==bNum && px==x)
    {
        printf("FILL(2)\n");
        return ;
    }
    
    /* OP 3: DROP(i) */
    if (px!=0 && x==0 && py==y)
    {
        printf("DROP(1)\n");
        return ;
    }
    
    /* OP 4: DROP(j) */
    if (py!=0 && y==0 && px==x)
    {
        printf("DROP(2)\n");
        return ;
    }
    
    /* POUR(i, j) or POUR(j, i)*/
    if (px+py == x+y)
    {
        if (x==0 || y==bNum)
        {
            printf("POUR(1,2)\n");
        }
        else
        {
            printf("POUR(2,1)\n");
        }
        return ;
    }
}/* DFS */

void BFS()
{
    int front = -1;
    int rear  = -1;
    int isSolve = 0; /* Define a flag */
    
    ver.a = 0;
    ver.b = 0;
    ver.step = 0;
    vis[0][0] = 1;
    q[++rear] = ver;
    
    while (front != rear)
    {   /* 队列不为空时循环 */ 
        ver = q[++front];
        
        if (ver.a==cNum || ver.b==cNum)
        {   /* 查找成功 */
            printf("%d\n", ver.step);
            
            DFS(ver.a, ver.b);
            isSolve = 1;
            break;
        }/* End of If */
        
        /* 操作次数增加一 */ 
        temp.step = ver.step + 1;
        
        /* OP 1: Fill(i) */
        temp.a = aNum;
        temp.b = ver.b;
        if (!vis[temp.a][temp.b])
        {
            vis[temp.a][temp.b] = 1;
            prev[temp.a][temp.b].prex = ver.a;
            prev[temp.a][temp.b].prey = ver.b;
            q[++rear] = temp;
        }
        
        /* OP 2: Fill(j) */
        temp.a = ver.a;
        temp.b = bNum;
        if (!vis[temp.a][temp.b])
        {
            vis[temp.a][temp.b] = 1;
            prev[temp.a][temp.b].prex = ver.a;
            prev[temp.a][temp.b].prey = ver.b;
            q[++rear] = temp;
        }
        
        /* OP 3: DROP(i) */
        temp.a = 0;
        temp.b = ver.b;
        if (!vis[temp.a][temp.b])
        {
            vis[temp.a][temp.b] = 1;
            prev[temp.a][temp.b].prex = ver.a;
            prev[temp.a][temp.b].prey = ver.b;
            q[++rear] = temp;
        }
        
        /* OP 4: DROP(j) */
        temp.a = ver.a;
        temp.b = 0;
        if (!vis[temp.a][temp.b])
        {
            vis[temp.a][temp.b] = 1;
            prev[temp.a][temp.b].prex = ver.a;
            prev[temp.a][temp.b].prey = ver.b;
            q[++rear] = temp;
        }
        
        /* OP 5: POUR(i, j) */
        temp.b = (ver.a+ver.b)<bNum ? (ver.a+ver.b) : bNum;
        temp.a = ver.a - (temp.b - ver.b);
        if (!vis[temp.a][temp.b])
        {
            vis[temp.a][temp.b] = 1;
            prev[temp.a][temp.b].prex = ver.a;
            prev[temp.a][temp.b].prey = ver.b;
            q[++rear] = temp;
        }
        
        /* OP 6: POUR(j, i) */
        temp.a = (ver.a+ver.b)<aNum ? (ver.a+ver.b) : aNum;
        temp.b = ver.b - (temp.a - ver.a);
        if (!vis[temp.a][temp.b])
        {
            vis[temp.a][temp.b] = 1;
            prev[temp.a][temp.b].prex = ver.a;
            prev[temp.a][temp.b].prey = ver.b;
            q[++rear] = temp;
        }
    }/* End of While */
    if (!isSolve)
    {
        printf("impossible\n");
    }
}/* BFS */

int main()
{
#ifdef onlinejudge
    freopen("E:\\poj3414.txt", "r", stdin);
    freopen("E:\\poj3414(result).txt", "w", stdout);
#endif

    while (3 == scanf("%d %d %d", &aNum, &bNum, &cNum))
    {
        /* Empty the 2D array */
        memset(vis, 0, sizeof(vis));
        memset(prev, 0, sizeof(prev));
        
        BFS();
    }/* End of While */
    
    return 0;
}

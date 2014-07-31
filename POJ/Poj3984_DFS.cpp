#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int maze[10][10]={0};
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct path
{
    int x;
    int y;
    int dir;
}stack[30]={0};

int IsInBound(int x, int y)
{
    if (x<0 || y<0 || x>=5 || y>=5)
        return 0;
    
    return 1;
}/* IsInBound */

void PrintPath(int n)
{
    int i;
    
    for (i=0; i<=n; ++i)
    {
        printf("(%d, %d)\n", stack[i].x, stack[i].y);
    }/* End of For */
}/* PrintPath */

void DFS()
{
    int dir, IsFind, top = -1;
    struct path cur, next;
    
    cur.x = 0;
    cur.y = 0;
    cur.dir = -1;
    stack[++top] = cur;
    
    maze[0][0] = -1;
    while (top != -1)
    {
        cur = stack[top], dir = stack[top].dir;
        if (cur.x==4 && cur.y==4)
        {   /* 表示已经找到出口，打印路径 */ 
            PrintPath(top);
            break;
        }/* End of If */
        
        IsFind = 0;
        while (dir<4 && IsFind==0)
        {   /* 从上下左右4个方向分别探索 */ 
            ++dir;
            
            next.x = cur.x + dx[dir];
            next.y = cur.y + dy[dir];
            
            if (IsInBound(next.x, next.y) && !maze[next.x][next.y])
            {   /* 可行位置 */
                IsFind = 1;
            }
        }/* End of For */
        if (IsFind)
        {
            next.dir = -1;
            stack[top].dir = dir;
            stack[++top] = next;
            maze[stack[top].x][stack[top].y] = -1;
        }
        else
        {
            maze[stack[top].x][stack[top].y] = 0;
            --top;
        }
    }/* End of While */
}/* DFS */

int main()
{
    int i, j;
    
    for (i=0; i<5; ++i)
    {
        for (j=0; j<5; ++j)
        {
            scanf("%d", &maze[i][j]);
        }    
    }/* End of For */
    
    DFS();
        
    system("pause");
    return 0;
}

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define onlinejudge

int mat[1010][1010];
int i, nNum, tx, ty, ai, bi;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct path
{
    int x, y, step;
}q[1000010]={0};

int IsInBound(int x, int y)
{
    if (x<0 || y<0|| x>1000 || y>1000)
    {
        return 0;
    }
    
    return 1;
}/* IsInBound */

void BFS()
{
    int rear = -1;
    int k, front = -1;
    struct path cur, next;
    
    cur.x = 500;
    cur.y = 500;
    cur.step = 0;
    q[++rear] = cur;
    
    mat[500][500] = 1;
    while (front < rear)
    {
        cur = q[++front];
        if (cur.x==500-ty && cur.y==500+tx)
        {
            printf("%d\n", cur.step);
            break;
        }/* End of If */
        
        for (k=0; k<4; ++k)
        {
            next.x = cur.x + dx[k];
            next.y = cur.y + dy[k];
            if (IsInBound(next.x, next.y) && mat[next.x][next.y]==0)
            {
                mat[next.x][next.y] = 1;
                next.step = cur.step + 1;
                q[++rear]  = next;
            }
        }/* End of For */
    }/* End of WHile */
}/* BFS */

int main()
{
#ifdef onlinejudge
    freopen("E:\\poj3626.txt", "r", stdin);
    freopen("E:\\poj3626(result).txt", "w", stdout);
#endif

    while (3 == scanf("%d %d %d", &tx, &ty, &nNum))
    {
        memset(mat, 0, sizeof(mat));
        for (i=0; i<nNum; ++i)
        {
            scanf("%d %d", &ai, &bi);
            mat[500-bi][500+ai] = 1;
        }/* End of For */
        
        BFS();
    }/* End of While */
    
    return 0;
}

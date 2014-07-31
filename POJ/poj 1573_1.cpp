#include <stdio.h>
#include <string.h>

//#define onlinejudge

const int maxn = 20;

char maze[maxn][maxn];
int  n, m, s, sx, sy, tx, ty, step[maxn][maxn];

bool IsInBound(int x, int y)
{
    if (x<0 || y<0 || x>=n || y>=m)
        return false;
    
    return true;
}/* IsInBound */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1035.txt", "r", stdin);
    freopen("E:\\hdoj_1035_ans.txt", "w", stdout);
#endif

    while (~scanf("%d %d %d", &n, &m, &s), n+m+s!=0)
    {
        memset(step, 0, sizeof(step));
        
        for (int i=0; i<n; ++i)
            scanf("%s", maze[i]);

        step[0][s-1]=1;
        sx=tx=0, sy=ty=s-1;
        while (1)
        {
            sx = tx, sy = ty;
            switch (maze[tx][ty])
            {
                case 'N': tx=sx-1, ty=sy; break;
                case 'E': ty=sy+1, tx=sx; break;
                case 'S': tx=sx+1, ty=sy; break;
                case 'W': ty=sy-1, tx=sx; break;
            }
            
            if (IsInBound(tx, ty) && !step[tx][ty])
                step[tx][ty] = step[sx][sy] + 1;
            else
                break;
            ////////////////////////////////////////////////////////////////////////////////////
            //printf("%d %d %d %d %d\n", sx, sy, tx, ty, step[tx][ty]);    ///******************************
            ///////////////////////////////////////////////////////////////////////////////////////
        }

        if (!IsInBound(tx, ty))
            printf("%d step(s) to exit\n", step[sx][sy]);
        else
        {
            //printf("%d %d\n", step[sx][sy], step[tx][ty]);
            printf("%d step(s) before a loop of %d step(s)\n", step[tx][ty]-1, step[sx][sy]-step[tx][ty]+1);
        }
    }/* End of While */
    
    return 0;
}

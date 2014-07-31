#include <stdio.h>
#include <string.h>

#define onlinejudge

const int maxn = 12;

char maze[maxn][maxn];
int  n, m, s, step, vis[maxn][maxn];
struct pn
{
    int px, py;
}p[maxn][maxn];

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
        memset(p, 0, sizeof(p));
        memset(vis, 0, sizeof(vis));

        for (int i=0; i<n; ++i)
            scanf("%s", maze[i]);
/***
        for (int i=0; i<n; ++i)
        {
            for (int j=0; j<m; ++j)
                printf("%c", maze[i][j]);
            printf("\n");
        }
***/
        step = 0;
        vis[0][s-1] = 0;
        
        int sx, sy, tx, ty;
        
        sx = tx = 0, sy = ty = s-1;
        while (IsInBound(tx, ty) && !vis[tx][ty])
        {
            step++;
            vis[tx][ty] = 1;
            //////////////////////////////////////////
            //printf("%d %d %c %d %d %c %2d\n",
            //p[tx][ty].px, p[tx][ty].py, maze[p[tx][ty].px][p[tx][ty].py], tx, ty, maze[tx][ty], step);
            //////////////////////////////////////////
            switch (maze[tx][ty])
            {
                case 'N': tx=sx-1, ty=sy; break;
                case 'E': ty=sy+1, tx=sx; break;
                case 'S': tx=sx+1, ty=sy; break;
                case 'W': ty=sy-1, tx=sx; break;
            }
            
            p[tx][ty].px = sx;
            p[tx][ty].py = sy;
            sx = tx, sy = ty;
        }/* End of While */

        if (!IsInBound(tx, ty))
            printf("%d\n", step);
        else
        {
            int res = 0;
            ////////////////////////////////////////////////
            //printf("#%d %d %d %d %d %d#\n", sx, sy, tx, ty, p[tx][ty].px, p[tx][ty].py); //-------------------------------------------
            /////////////////////////////////////////////////
            tx = p[sx][sy].px, ty = p[sx][sy].py;
            while (tx!=sx && ty!=sy)
            {
                printf("%d %d %d %d\n", sx, sy, tx, ty);
                
                ++res;
                tx = p[tx][ty].px;
                ty = p[tx][ty].py;
            }
            
            printf("%d\n", res);
        }

        printf("\n");   //----------------------------------------------------------
        //printf("%d\n\n", step); //--------------------------------------------
    }/* End of While */
    
    return 0;
}

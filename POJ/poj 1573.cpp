#include <stdio.h>
#include <string.h>

#define onlinejudge

const int maxn = 12;

char maze[maxn][maxn];
int  n, m, s, vis[maxn][maxn];

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
        memset(vis, 0, sizeof(vis));

        for (int i=0; i<n; ++i)
            scanf("%s", maze[i]);
        
        int sx, sy, tx, ty, px, py;
        
        vis[0][s-1] = 0;
        sx = tx = 0, sy = ty = s-1;
        while ()
        {
            switch (maze[tx][ty])
            {
                
            }
        }
/***
        if (!IsInBound(tx, ty))
            printf("%d\n", vis[px][py]);
****/
    }/* End of While */
    
    return 0;
}

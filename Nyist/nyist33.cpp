#include <stdio.h>

const int maxn = 104;

int sx, sy, cnt;
int n, mat[maxn][maxn];

int main()
{
    while (~scanf("%d", &n))
    {
        cnt = 1;
        for (int i=0; i<n; ++i)
        {   // Rounds
            sx = i, sy = n-i-1;
            for (int d=sx; d<=n-i-1; ++d)
                mat[d][sy] = cnt++;     // down
            
            if (cnt-1 == n*n)   break;
            
            sx = n-i-1, sy = sy-1;
            for (int l=sy; l>=i; --l)
                mat[sx][l] = cnt++;     // left
            
            if (cnt-1 == n*n)   break;
            
            sx = sx-1, sy = i;
            for (int u=sx; u>=i; --u)
                mat[u][sy] = cnt++;     // up
            
            if (cnt-1 == n*n)   break;
        
            sx = i, sy = sy+1;
            for (int r=sy; r<=n-i-2; ++r)
                mat[sx][r] = cnt++;     // right
            
            if (cnt-1 == n*n)   break;
        }/* End of For */
        
        for (int i=0; i<n; ++i)
        {
            for (int j=0; j<n; ++j)
                printf(j==0 ? "%d":" %d", mat[i][j]);
            printf("\n");
        }
    }/* End of While */
    
    return 0;
}

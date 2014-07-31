/*
PROG:   Zipper
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

const int maxn = 1004;

bool hash[maxn][maxn];
int  N, cas, alen, blen, clen;
char a[maxn], b[maxn], c[maxn];

bool dfs(int i, int j, int k, int depth)
{
    if (k == clen)
        return true;
    if (depth >= clen)
        return false;
    if (hash[i][j])
        return false;
    
    hash[i][j] = true;
    if (i < alen)
    {
        if (a[i]==c[k] && dfs(i+1, j, k+1, depth+1))
            return true;
    }
    if (j < blen)
    {
        if (b[j]==c[k] && dfs(i, j+1, k+1, depth+1))
            return true;
    }
    
    return false;
}// dfs

int main()
{
    while (~scanf("%d", &N))
    {
        for (cas=1; cas<=N; ++cas)
        {
            getchar();
            scanf("%s %s %s", a, b, c);
            
            alen = strlen( a );
            blen = strlen( b );
            clen = strlen( c );
            if (clen != alen+blen)
            {
                printf("Data set %d: no\n", cas);
                continue;
            }// clen is not equate to alen+blen
            
            memset(hash, false, sizeof(hash));
            if ( dfs(0, 0, 0, 0) )
                printf("Data set %d: yes\n", cas);
            else
                printf("Data set %d: no\n", cas);
        }// End of For
    }// End of while
    
    return 0;
}

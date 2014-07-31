#include <stdio.h>
#include <memory.h>

#define onlinejudge

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

const int maxn = 100000;

int n, a, b, tmp, cnt[maxn<<2];

void UpData(int L, int R, int l, int r, int rt)
{
    if (L<=l && r<=R)
    {
        ++cnt[rt];
        
        ///////////
        printf("#%d %d %d#\n", l, r, cnt[rt]);
        ////////////////////
        
        return ;
    }/* End of IF */
    
    int m = (l+r)>>1;
    if (L <= m)
        UpData(L, R, lson);
    if (R > m)
        UpData(L, R, rson);
        
    cnt[rt] = cnt[rt<<1] + cnt[rt<<1|1];
}/* UpData */

void Query(int l, int r, int rt)
{
    if (l == r)
    {
        /****
        printf("#%d %d %d#\n", l, r, cnt[rt]);
        ******/
        //printf(tmp==1 ? "%d":" %d", cnt[rt]);
        
        tmp++;
        return ;
    }/* End of If */
    
    int m = (l+r)>>1;
    Query(lson);
    Query(rson);
}/* Query */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj1556.txt", "r", stdin);
    freopen("E:\\hdoj1556_ans.txt", "w", stdout);
#endif

    while (~scanf("%d", &n), n!=0)
    {
        /* Initialized */
        memset(cnt, 0, sizeof(cnt));

        for (int i=1; i<=n; ++i)
        {
            scanf("%d %d", &a, &b);
            UpData(a, b, 1, n, 1);
        }/* End of For */
        
        tmp = 1;
        Query(1, n, 1);
        printf("\n");
    }/* End of While */
    
    return 0;
}

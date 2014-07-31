#include <stdio.h>

//#define onlinejudge

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

const int maxn = 200000;

char cmd[2];
int  n, mNum, a, b, max[maxn<<2];

int Max(int x, int y)
{
    return (x>y ? x:y);
}/* Max */

void BuildTree(int l, int r, int rt)
{
    if (l == r)
    {
        scanf("%d", &max[rt]);
        return ;
    }/* End of If */
    
    int m = (l+r)>>1;
    BuildTree(lson);
    BuildTree(rson);
    max[rt] = Max(max[rt<<1], max[rt<<1|1]);    /* Push Up */
}/* BuildTree */

int Query(int L, int R, int l, int r, int rt)
{
    if (L<=l && r<=R)
        return max[rt];
    
    int ret=-1, m=(l+r)>>1;

    if (L <= m)
        ret = Max(ret, Query(L, R, lson));
    if (R > m)
        ret = Max(ret, Query(L, R, rson));

    return ret;
}/* Query */

void UpData(int p, int bi, int l, int r, int rt)
{
    if (l == r)
    {
        max[rt] = bi;
        return ;
    }/* End of If */

    int m = (l+r)>>1;

    if (p <= m)
        UpData(p, bi, lson);
    else
        UpData(p, bi, rson);
        
    max[rt] = Max(max[rt<<1], max[rt<<1|1]);    /* Push Up */
}/* UpData */

int main()
{
#ifdef onlinejudge
    freopen("D:\\hdoj1754.txt", "r", stdin);
    freopen("D:\\hdoj1754_ans.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &n, &mNum))
    {
        BuildTree(1, n, 1);
        for (int i=1; i<=mNum; ++i)
        {
            scanf("%s %d %d", cmd, &a, &b);
            if (cmd[0] == 'Q')  /* Query */
                printf("%d\n", Query(a, b, 1, n, 1));
            else    /* UpData */
                UpData(a, b, 1, n, 1);
        }
    }/* End of While */
    
    return 0;
}

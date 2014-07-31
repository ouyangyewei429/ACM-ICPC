#include <stdio.h>

//#define onlinejudge

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

const int maxn = 100000;

int casenum, n, mNum, a, b, c;
int sum[maxn<<2], col[maxn<<2];

void BuildTree(int l, int r, int rt)
{
    col[rt] = 0;
    sum[rt] = 1;
    if (l == r)
        return ;
        
    int m = (l+r)>>1;
    BuildTree(lson);
    BuildTree(rson);
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}/* BuildTree */

void UpData(int L, int R, int c, int l, int r, int rt)
{
    if (L<=l && r<=R)
    {
        col[rt] = c;
        sum[rt] = c*(r-l+1);
        return ;
    }
    
    /* PushDown(rt, r-l+1) */
    int k = r-l+1;
    if (col[rt])
    {
        col[rt<<1] = col[rt<<1|1] = col[rt];
        sum[rt<<1] = col[rt]*(k-(k>>1));
        sum[rt<<1|1] = col[rt]*(k>>1);
        col[rt] = 0;
    }
    
    int m = (l+r)>>1;
    if (L <= m)
        UpData(L, R, c, lson);
    if (R > m)
        UpData(L, R, c, rson);
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}/* UpData */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj1698.txt", "r", stdin);
    freopen("E:\\hdoj1698_ans.txt", "w", stdout);
#endif

    scanf("%d", &casenum);
    for (int cas=1; cas<=casenum; ++cas)
    {
        scanf("%d %d", &n, &mNum);
        
        BuildTree(1, n, 1);
        for (int i=1; i<=mNum; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            UpData(a, b, c, 1, n, 1);
        }/* End of For */
        
        printf("Case %d: The total value of the hook is %d.\n", cas, sum[1]); 
    }/* End of While */
    
    return 0;
}

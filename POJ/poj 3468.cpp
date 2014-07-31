#include <stdio.h>

#define onlinejudge

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

const int maxn = 100004;

char     cmd[2];
int      n, mNum, a, b, c;
__int64  sum[maxn<<2]={0}, col[maxn<<2]={0};

void BuildTree(int l, int r, int rt)
{
    col[rt] = 0;
    if (l == r)
    {
        scanf("%I64d", &sum[rt]);
        return ;
    }/* End of If */
    
    int m = (l+r)>>1;
    BuildTree(lson);
    BuildTree(rson);
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];    /* Push Up */
}/* BuildTree */

void PushDown(int rt, int k)
{
    if (col[rt])
    {
        col[rt<<1] += col[rt];
        col[rt<<1|1] += col[rt];
        sum[rt<<1] += col[rt]*(k-(k>>1));
        sum[rt<<1|1] += col[rt]*(k>>1);
        col[rt] = 0;
    }
}/* PushDown */

__int64 Query(int L, int R, int l, int r, int rt)
{
    if (L<=l && r<=R)
        return sum[rt];
    
    PushDown(rt, r-l+1);    /* Push down */
    
    __int64 ret = 0;
    int     m = (l+r)>>1;

    if (L <= m)
        ret += Query(L, R, lson);
    if (R > m)
        ret += Query(L, R, rson);

    return ret;
}/* Query */

void UpData(int L, int R, int c, int l, int r, int rt)
{
    if (L<=l && r<=R)
    {
        col[rt] += c;
        sum[rt] += c*(r-l+1);
        
        return ;
    }/* End of If */

    PushDown(rt, r-l+1);    /* Push down */

    int m = (l+r)>>1;

    if (L <= m)
        UpData(L, R, c, lson);
    if (R > m)
        UpData(L, R, c, rson);
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];    /* Push Up */
}/* UpData */

int main()
{
#ifdef onlinejudge
    freopen("D:\\poj3468.txt", "r", stdin);
    freopen("D:\\poj3468_ans.txt", "w", stdout);
#endif

    scanf("%d %d", &n, &mNum);
    
    BuildTree(1, n, 1);
    for (int i=1; i<=mNum; ++i)
    {
        scanf("%s", cmd);
        if (cmd[0] == 'Q')
        {   /* Query */
            scanf("%d %d", &a, &b);
            printf("%I64d\n", Query(a, b, 1, n, 1));
        }
        else
        {   /* Add */
            scanf("%d %d %d", &a, &b, &c);
            UpData(a, b, c, 1, n, 1);
        }
    }/* End of For */
    
    return 0;
}

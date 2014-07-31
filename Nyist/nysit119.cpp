#include <stdio.h>

//#define onlinejudge

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

const int maxn = 100000;
const int INF  = 0x3F3F3F3F;

int n, mNum, a, b;
struct tree
{
    int val, max, min;
}ans, sum[maxn<<2];

int Max(int x, int y)
{
    return (x>y ? x:y);
}/* Max */

int Min(int x, int y)
{
    return (x<y ? x:y);
}/* Min */

void PushUp(int rt)
{
    sum[rt].max = Max(sum[rt<<1].max, sum[rt<<1|1].max);
    sum[rt].min = Min(sum[rt<<1].min, sum[rt<<1|1].min);
}/* PushUp */

void BuildTree(int l, int r, int rt)
{
    if (l == r)
    {
        scanf("%d", &sum[rt].val);
        sum[rt].max = sum[rt].min = sum[rt].val;
        
        return ;
    }
    
    int m = (l+r)>>1;
    BuildTree(lson);
    BuildTree(rson);
    PushUp(rt);
}/* BuildTree */

struct tree Query(int L, int R, int l, int r, int rt)
{
    if (L<=l && r<=R)
        return sum[rt];
    
    int m = (l+r)>>1;
    struct tree res = {0, -1, INF};
    struct tree tmp = {0, -1, INF};
    
    if (L <= m)
    {
        tmp = Query(L, R, lson);
        res.max = Max(res.max, tmp.max);
        res.min = Min(res.min, tmp.min);
    }
    if (R > m)
    {
        tmp = Query(L, R, rson);
        res.max = Max(res.max, tmp.max);
        res.min = Min(res.min, tmp.min);
    }
    
    return res;
}/* Query() */

int main()
{
#ifdef onlinejudge
    freopen("E:\\nysit119.txt", "r", stdin);
    freopen("E:\\nyist119_ans.txt", "w", stdout);
#endif
    
    scanf("%d %d", &n, &mNum);
    
    BuildTree(1, n, 1);
    for (int i=1; i<=mNum; ++i)
    {
        scanf("%d %d", &a, &b);
        
        ans = Query(a, b, 1, n, 1);
        printf("%d\n", ans.max-ans.min);
    }/* End of For */

    return 0;
}

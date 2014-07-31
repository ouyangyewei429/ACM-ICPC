#include <stdio.h>

#define onlinejudge

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

const int maxn = 1000000;

int n, mNum, a, b, sum[maxn<<2];

void PushUp(int rt)
{
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}/* PushUp */

void BuildTree(int l, int r, int rt)
{
    if (l == r)
    {
        scanf("%d", &sum[rt]);
        return ;
    }
    
    int m = (l+r)>>1;
    BuildTree(lson);
    BuildTree(rson);
    PushUp(rt);
}/* BuildTree */

int Query(int L, int R, int l, int r, int rt)
{
    if (L<=l && r<=R)
        return sum[rt];
    
    int ret=0, m = (l+r)>>1;
    if (L <= m)     ret += Query(L, R, lson);
    if (R > m)      ret += Query(L, R, rson);
    
    return ret;
}/* Query */

int main()
{
#ifdef onlinejudge
    freopen("E:\\nyist108.txt", "r", stdin);
    freopen("E:\\nyist108_ans.txt", "w", stdout);
#endif

    scanf("%d %d", &n, &mNum);
    
    BuildTree(1, n, 1);
    for (int i=1; i<=mNum; ++i)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", Query(a, b, 1, n, 1));
    }/* End of For */
    
    return 0;
}

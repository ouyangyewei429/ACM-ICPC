#include <stdio.h>

#define onlinejudge

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

const int maxn = 1000000;

char cmd[6] = {0};
int  n, mNum, a, b, sum[maxn<<2];

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
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}/* BuildTree */

int Query(int L, int R, int l, int r, int rt)
{
    if (L<=l && r<=R)
        return sum[rt];
    
    int ret=0, m=(l+r)>>1;
    if (L <= m)     ret += Query(L, R, lson);
    if (R > m)      ret += Query(L, R, rson);
    
    return ret;
}/* Query */

void UpData(int p, int ai, int l, int r, int rt)
{
    if (l == r)
    {
        sum[rt] += ai;
        return ;
    }
    
    int m = (l+r)>>1;
    if (p <= m)     UpData(p, ai, lson);
    if (p > m)      UpData(p, ai, rson);
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}/* UpData */

int main()
{
#ifdef onlinejudge
    freopen("E:\\nyist116.txt", "r", stdin);
    freopen("E:\\nyist116_ans.txt", "w", stdout);
#endif

    scanf("%d %d", &n, &mNum);
    
    BuildTree(1, n, 1);
    for (int i=1; i<=mNum; ++i)
    {
        scanf("%s %d %d", cmd, &a, &b);
        
        if (cmd[0] == 'Q')
            printf("%d\n", Query(a, b, 1, n, 1));
        else
            UpData(a, b, 1, n, 1);
    }/* End of For */
    
    return 0;
}

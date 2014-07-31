#include <stdio.h>

//#define onlinejudge

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

const int maxn = 1000000;

char cmd[6] = {0};
int  n, mNum, a, b, c;
int  sum[maxn<<2]={0}, col[maxn<<2]={0};

void PushDown(int rt, int k)
{
    if (col[rt])
    {
        col[rt<<1] +=  col[rt];
        col[rt<<1|1] += col[rt];
        sum[rt<<1] += (k-(k>>1))*col[rt];
        sum[rt<<1|1] += (k>>1)*col[rt];
        col[rt] = 0;
    }
}/* PushDown */

void UpData(int L, int R, int c, int l, int r, int rt)
{
    if (L<=l && r<=R)
    {
        col[rt] += c;
        sum[rt] += c*(r-l+1);
        return ;
    }
    
    PushDown(rt, r-l+1);
    
    int m = (l+r)>>1;
    if (L <= m)
        UpData(L, R, c, lson);
    if (R > m)
        UpData(L, R, c, rson);
    
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}/* UpData */

int Query(int p, int l, int r, int rt)
{
    if (l == r)
        return sum[rt];
    
    PushDown(rt, r-l+1);
    
    int ret=0, m=(l+r)>>1;
    if (p <= m)
        ret += Query(p, lson);
    else
        ret += Query(p, rson);
    
    return ret;
}/* Query */

int main()
{
#ifdef onlinejudge
    freopen("E:\\nyist123.txt", "r", stdin);
    freopen("E:\\nyist123_ans.txt", "w", stdout);
#endif

    scanf("%d %d", &mNum, &n);
    for (int i=1; i<=mNum; ++i)
    {
        scanf("%s", cmd);
        if (cmd[0] == 'A')
        {   /* Add */
            scanf("%d %d %d", &a, &b, &c);
            UpData(a, b, c, 1, n, 1);
        }
        else
        {   /* Query */
            scanf("%d", &a);
            printf("%d\n", Query(a, 1, n, 1));
        }
    }/* End of For */
    
    return 0;
}

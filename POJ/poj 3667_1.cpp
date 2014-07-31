#include <stdio.h>

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

const int maxn = 50010;

int n, mNum, a, b, cmd;
int sum[maxn*3], lsum[maxn*3], rsum[maxn*3], cover[maxn*3];

int Max(int x, int y)
{
    return (x>y ? x:y);
}/* Max */

void BuildTree(int l, int r, int rt)
{
    cover[rt]=-1;
    sum[rt]=lsum[rt]=rsum[rt]=r-l+1;
    
    if (l == r)
        return ;
    
    int m = (l+r)>>1;
    BuildTree(lson);
    BuildTree(rson);
}/* BuildTree */

void pushdown(int rt, int k)
{
    if (cover[rt] != -1)
    {
        cover[rt<<1]=cover[rt<<1|1]=cover[rt];
        sum[rt<<1]=lsum[rt<<1]=rsum[rt<<1]=cover[rt] ? 0:k-(k>>1);
        sum[rt<<1|1]=lsum[rt<<1|1]=rsum[rt<<1|1]=cover[rt] ? 0:(k>>1);
        cover[rt]=-1;
    }
}/* pushdown */

void pushup(int rt, int k)
{
    lsum[rt] = lsum[rt<<1];
    rsum[rt] = rsum[rt<<1|1];
    
    if (lsum[rt] == k-(k>>1))
        lsum[rt] += lsum[rt<<1|1];
    if (rsum[rt] == (k>>1))
        rsum[rt] += rsum[rt<<1];
    
    sum[rt] = Max(rsum[rt<<1]+lsum[rt<<1|1], Max(sum[rt<<1], sum[rt<<1|1]));
}/* pushup */

void updata(int L, int R, int flag, int l, int r, int rt)
{
    if (L<=l && r<=R)
    {
        sum[rt]=lsum[rt]=rsum[rt]=flag ? 0:r-l+1;
        cover[rt] = flag;
        return ;
    }/* End of If */
    
    pushdown(rt, r-l+1);
    
    int m = (l+r)>>1;
    if (L <= m)
        updata(L, R, flag, lson);
    if (R > m)
        updata(L, R, flag, rson);
    
    pushup(rt, r-l+1);
}/* updata */

int query(int w, int l, int r, int rt)
{
    if (l == r)
        return l;
    
    pushdown(rt, r-l+1);
    
    int m = (l+r)>>1;
    if (sum[rt<<1] >= w)
        return query(w, lson);
    else if (rsum[rt<<1]+lsum[rt<<1|1] >= w)
        return m-rsum[rt<<1]+1;
    else
        return query(w, rson);
}/* query */

int main()
{
    scanf("%d %d", &n, &mNum);
    
    BuildTree(1, n, 1);
    for (int i=1; i<=mNum; ++i)
    {
        scanf("%d", &cmd);
        if (cmd == 1)
        {   /* check in */
            scanf("%d", &a);
            if (sum[1] < a)
                printf("0\n");
            else
            {
                int p = query(a, 1, n, 1);
                printf("%d\n", p);
                updata(p, p+a-1, 1, 1, n, 1);
            }
        }
        else
        {   /* check out */
            scanf("%d %d", &a, &b);
            updata(a, a+b-1, 0, 1, n, 1);
        }
    }/* End of For */
    
     return 0; 
}



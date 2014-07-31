#include <stdio.h>

//#define onlinejudge

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

const int maxn = 50000;

int n, mNum, op, a, b;
int sum[maxn*3], lsum[maxn*3], rsum[maxn*3], cover[maxn*3];

void BuildTree(int l, int r, int rt)
{
    cover[rt] = -1;
    lsum[rt] = rsum[rt] = sum[rt] = r-l+1;
    if (l == r)
        return ;
    
    int m = (l+r)>>1;
    BuildTree(lson);
    BuildTree(rson);
}/* BuildTree */

void PushDown(int rt, int k)
{
    if (cover[rt] != -1)
    {   /* Lazy Tag */
        cover[rt<<1] = cover[rt<<1|1] = cover[rt];
        lsum[rt<<1] = rsum[rt<<1] = sum[rt<<1] = cover[rt] ? 0:(k-(k>>1)); 
        lsum[rt<<1|1] = rsum[rt<<1|1] = sum[rt<<1|1] = cover[rt] ? 0:(k>>1);
        cover[rt] = -1;
    }
}/* PushDown */

int query(int w, int l, int r, int rt)
{
    if (l == r)
        return 1;
    
    PushDown(rt, r-l+1);    /* Push Down */
    
    int m = (l+r)>>1;
    if (sum[rt<<1] >= w)    /* 左连续区间长度 */ 
        return query(w, lson);
    else if (rsum[rt<<1]+lsum[rt<<1|1] >= w) /* 左区间后半部分与右区间左半部分长度 */ 
        return m-rsum[rt<<1]+1;
    else                    /* 右连续区间长度 */ 
        return query(w, rson);
}/* query */

int Max(int x, int y)
{
    return (x>y ? x:y);
}/* Max */

void PushUp(int rt, int k)
{
    lsum[rt] = lsum[rt<<1];   /* 左区间的左半部分 */ 
    rsum[rt] = rsum[rt<<1|1]; /* 右区间的右半部分 */ 
    
    if (lsum[rt] == k-(k>>1))
        lsum[rt] += lsum[rt<<1|1];
    if (rsum[rt] == k>>1)
        rsum[rt] += rsum[rt<<1];
    
    sum[rt] = Max(rsum[rt<<1]+lsum[rt<<1|1], Max(sum[rt<<1], sum[rt<<1|1]));
}/* PushUp */

void UpData(int L, int R, int c, int l, int r, int rt)
{
    if (L<=l && r<=R)
    {
        lsum[rt] = rsum[rt] = sum[rt] = c ? 0 : r-l+1;
        cover[rt] = c;
        
        return ;
    }/* End of If */
    
    PushDown(rt, r-l+1);    /* Push Down */
    
    int m = (l+r)>>1;
    if (L <= m)
        UpData(L, R, c, lson);
    if (R > m)
        UpData(L, R, c, rson);
    
    PushUp(rt, r-l+1);      /* Push Up */
}/* Updata */

int main()
{
#ifdef onlinejudge
    freopen("E:\\poj3667.txt", "r", stdin);
	freopen("E:\\poj3667_ans.txt", "w", stdout);
#endif

    scanf("%d %d", &n, &mNum);
    
    BuildTree(1, n, 1); /* BuildTree */ 
    for (int i=1; i<=mNum; ++i)
    {
        scanf("%d", &op);
        if (op == 1)
        {   // Request
            scanf("%d", &a);
            if (sum[1] < a)
                printf("0\n");  /* No result */
            else
            {
                int pos = query(a, 1, n, 1);
                printf("%d\n", pos);
                UpData(pos, pos+a-1, 1, 1, n, 1);   /* UpData the interval */
            }
        }/* End of If */
        else
        {
            scanf("%d %d", &a, &b);
            UpData(a, a+b-1, 0, 1, n, 1);   /* UpData the interval */
        }
    }/* End of For */
    
    return 0;
}

#include <stack>
#include <cstdio>
using namespace std;

//#define onlinejudge

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

const int maxn = 50000;

char cmd[5];
stack <int> st;
int n, mNum, a;
int lsum[maxn*3], rsum[maxn*3], sum[maxn*3], cover[maxn*3];

int Max(int x, int y)
{
    return (x>y ? x:y);
}/* Max */

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
    {
        cover[rt<<1] = cover[rt<<1|1] = cover[rt];
        lsum[rt<<1] = rsum[rt<<1] = sum[rt<<1] = cover[rt] ? 0:k-(k>>1);
        lsum[rt<<1|1] = rsum[rt<<1|1] = sum[rt<<1|1] = cover[rt] ? 0:(k>>1);
        cover[rt] = -1;
    }
}/* PushDown */

int Query(int p, int l, int r, int rt)
{
    if (sum[rt]==0 || sum[rt]==r-l+1 || l==r)
        return sum[rt];
    
    PushDown(rt, r-l+1);
    
    int m = (l+r)>>1;
    if (p <= m)
    {
        if (p > m-rsum[rt<<1])
            return rsum[rt<<1]+Query(m+1, rson);
        else
            return Query(p, lson);
    }
    else
    {
        if (p <= m+lsum[rt<<1|1])
            return lsum[rt<<1|1]+Query(m, lson);
        else
            return Query(p, rson);
    }
}/* Query */

void PushUp(int rt, int k)
{
    lsum[rt] = lsum[rt<<1];
    rsum[rt] = rsum[rt<<1|1];
    
    if (lsum[rt] == k-(k>>1))
        lsum[rt] += lsum[rt<<1|1];
    if (rsum[rt] == (k>>1))
        rsum[rt] += rsum[rt<<1];
    
    sum[rt] = Max(rsum[rt<<1]+lsum[rt<<1|1], Max(sum[rt<<1], sum[rt<<1|1]));
}/* PushUp */

void UpData(int p, int c, int l, int r, int rt)
{
    if (l == r)
    {
        lsum[rt] = rsum[rt] = sum[rt] = c ? 0:r-l+1;
        cover[rt] = c;
        
        return ;
    }/* End of If */
    
    PushDown(rt, r-l+1);
    
    int m = (l+r)>>1;
    if (p <= m)
        UpData(p, c, lson);
    else
        UpData(p, c, rson);
    
    PushUp(rt, r-l+1);
}/* UpData */

/*****
void display(char cmd, int num)
{
    printf("\n%c %d\n--------------------------------\n", cmd, num);
    for (int i=1; i<=13; ++i)
        printf("%2d --> %d %d %d\n",
        i, lsum[i], rsum[i], sum[i]);
    printf("\n");
}
*******/

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj1540.txt", "r", stdin);
    freopen("E:\\hdoj1540_ans.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &n, &mNum))
    {
        BuildTree(1, n, 1);
        
        while (!st.empty())
            st.pop();
        
        for (int i=1; i<=mNum; ++i)
        {
            scanf("%s", cmd);
            if (cmd[0] == 'Q')
            {
                scanf("%d", &a);
                printf("%d\n", Query(a, 1, n, 1));
            }
            else if (cmd[0] == 'D')
            {
                scanf("%d", &a);
                UpData(a, 1, 1, n, 1);
                /******
                display(cmd[0], a);
                ******/
                st.push(a);
            }
            else
            {
                a = st.top();
                st.pop();
                UpData(a, 0, 1, n, 1);
                ////////////////////////////////////////////////
                //display(cmd[0], a);
                ////////////////////////////////////////////////
            }
        }/* End of For */
    }/* End of While */    
    
    return 0;
}


#include <stdio.h>
#include <memory.h>

//#define onlinejudge

const int maxn = 50004;

char cmd[6] = {0};
int  casenum, n, a, b, tree[maxn<<2];

void BuildTree(int l, int r, int rt)
{
    if (l == r)
    {
        scanf("%d", &tree[rt]);
        return ;
    }

    int m = (l+r)>>1;
    BuildTree(l, m, rt<<1);    /* Build the left tree */
    BuildTree(m+1, r, rt<<1|1);  /* Build the right tree */
    tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}/* BuildTree */

int Query(int L, int R, int l, int r, int rt)
{
    if (L<=l && r<=R)
        return tree[rt];
        
    int m = (l+r)>>1;
    int ret = 0;
    if (L <= m)     ret += Query(L, R, l, m, rt<<1);
    if (R > m)      ret += Query(L, R, m+1, r, rt<<1|1);
    
    return ret;
}/* Query */

void UpData(int xx, int ai, int l, int r, int rt)
{
    if (l == r)
    {
        tree[rt] += ai;
        return ;
    }
    
    int m = (l+r)>>1;
    if (xx <= m)
        UpData(xx, ai, l, m, rt<<1);
    else
        UpData(xx, ai, m+1, r, rt<<1|1);
    tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}/* UpData */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj1166.txt", "r", stdin);
    freopen("E:\\hdoj1166_ans.txt", "w", stdout);
#endif

    scanf("%d", &casenum);
    for (int i=1; i<=casenum; ++i)
    {        
        scanf("%d", &n);
        BuildTree(1, n, 1);

        printf("Case %d:\n", i);
        while (~scanf("%s", cmd), cmd[0]!='E')
        {
            scanf("%d %d", &a, &b);
            if (cmd[0] == 'Q')
                printf("%d\n", Query(a, b, 1, n, 1));
            else if (cmd[0] == 'A')
                UpData(a, b, 1, n, 1);
            else
                UpData(a, -b, 1, n, 1);
        }/* End of While */
    }/* End of For */

    return 0;
}

#include <stdio.h>

#define onlinejudge

const int maxn = 9;

bool IsSolved, hash[maxn];
int  T, cnt, tmp, dig[maxn];
int  graph[maxn][maxn]= {0, 0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 1, 1, 1, 0, 0, 0, 0,
                         0, 1, 0, 1, 0, 1, 1, 0, 0,
                         0, 1, 1, 0, 1, 1, 1, 1, 0,
                         0, 1, 0, 1, 0, 0, 1, 1, 0,
                         0, 0, 1, 1, 0, 0, 1, 0, 1,
                         0, 0, 1, 1, 1, 1, 0, 1, 1,
                         0, 0, 0, 1, 1, 0, 1, 0, 1,
                         0, 0, 0, 0, 0, 1, 1, 1, 0};
                         
void dfs(int n)
{
    if (n == 8)
    {
        ++cnt;
        IsSolved = true;
        return ;
    }/* End of IF */
    
    for (int p=1; p<=8; ++p)
    {
        if (dig[p])
            continue;
            
        for (int i=1; i<=8; ++i)    // 枚举每个数字，如果没有被使用过，则试放 */ 
        {
            if (hash[i])    // 数字被使用过，不去处理 
                continue;
            
            bool flag = true;
            for (int j=1; j<=8; ++j)
            {   /* 检查第 p 列 */ 
                if (j!=p && graph[j][p]
                    && dig[j] && (dig[j]==i-1 || dig[j]==i+1))
                {
                    flag = false;
                    break;
                }
            }/* End of for */
            if (flag)
            {
                dig[p]=i, hash[i]=true;
                dfs(n+1);
                dig[p]=0, hash[i]=false;
            }
        }/* End of For */
    }/* End of For */
}/* dfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_2514.txt", "r", stdin);
    freopen("E:\\hdoj_2514_ans.txt", "w", stdout);
#endif

    scanf("%d", &T);
    for (int cas=1; cas<=T; ++cas)
    {
        tmp = 0;    /* 记录不需要处理数字的个数 */ 
        for (int i=1; i<=8; ++i)
        {
            scanf("%d", &dig[i]);
            if (dig[i]) /* 数字不为零，则设定为已访问，因数字1-8只能使用一次 */ 
                tmp++, hash[i] = true;
            else
                hash[i] = false;
        }/* End of For */
        
        cnt = 0;    /* Result's number */
        IsSolved = false;
        dfs(tmp);
        
        printf("Case %d:", cas);
        if (!IsSolved)
            printf(" No answer\n");
        else if (cnt > 1)
            printf(" Not unique\n");
        else
        {
            for (int i=1; i<=8; ++i)
                printf(" %d", dig[i]);
            printf("\n");
        }
    }/* End of For */
    
    return 0;
}

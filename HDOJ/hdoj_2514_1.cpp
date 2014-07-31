#include <stdio.h>
#include <memory.h>

//#define onlinejudge

const int maxn = 9;

bool IsSolved, hash[maxn+1];
int  T, snum, cnt, p[maxn+1], dig[maxn+1];
int  graph[maxn][maxn]= {0, 0, 0, 0, 0, 0, 0, 0, 0,
                         0, 1, 1, 1, 1, 0, 0, 0, 0,
                         0, 1, 1, 1, 0, 1, 1, 0, 0,
                         0, 1, 1, 1, 1, 1, 1, 1, 0,
                         0, 1, 0, 1, 1, 0, 1, 1, 0,
                         0, 0, 1, 1, 0, 1, 1, 0, 1,
                         0, 0, 1, 1, 1, 1, 1, 1, 1,
                         0, 0, 0, 1, 1, 0, 1, 1, 1,
                         0, 0, 0, 0, 0, 1, 1, 1, 1};
                         
void dfs(int n, int count)
{
    if (n == 8)
    {
        ++snum;
        IsSolved = true;
        return ;
    }/* End of IF */
    
    for (int i=1; i<=8; ++i)
    {
        if (hash[i])    // 如果数字已被使用过，则不能再使用 
            continue;
        
        int  pos = p[count];
        for (int j=1; j<=8; ++j)
        {
            if (graph[j][pos]
                && (i>1&&dig[j]==i-1 || i<8&&dig[j]==i+1))
                break;
            
            if (j == 8)
            {
                dig[pos]=i, hash[i]=true;
                dfs(n+1, count+1);
                hash[i]=false;
            }
        }
    }
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
        cnt = 0;    /* 记录不需要处理数字的个数 */
        memset(p, 0, sizeof(p));
        memset(hash, false, sizeof(hash));
        for (int i=1; i<=8; ++i)
        {
            scanf("%d", &dig[i]);
            if (dig[i]) /* 数字不为零，则设定为已访问，因数字1-8只能使用一次 */ 
                hash[dig[i]]=true;
            else
                p[++cnt]=i;
        }/* End of For */
        
        snum = 0;    /* Result's number */
        IsSolved = false;
        dfs(8-cnt, 1);
        
        printf("Case %d:", cas);
        if (!IsSolved)
            printf(" No answer\n");
        else if (snum > 1)
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

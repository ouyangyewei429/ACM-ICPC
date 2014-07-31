#include <queue>
#include <stdio.h>
using namespace std;

#define onlinejudge

const int maxn = 10000000;

bool hash[maxn][maxn];
int  n, totHp, a[maxn], m[maxn];
struct SPELL
{
    int hp, 
}

void bfs()
{
    queue <int> q;
    int   index, ans=0, IsSolved=0;
    
    hp[0] = totHp;
    q.push(0);
    while (!q.empty())
    {
        index = q.front();
        q.pop();
        
        if (hp[index] <= 0)
        {
            ans=0, IsSolved=1;
            for (int i=1; i<=n; ++i)
            {
                if (hash[i])
                    ++ans;
            }
            
            printf("%d\n", ans);
            break;
        }/* End of IF */
        else
        {
            for (int i=1; i<=n; ++i)
            {
                if (!hash[i])
                {
                    hp[i] -= a[i];
                    if (hp[i] <= m[i])
                        hp[i] -= a[i];
                    
                    hash[i] = true;
                    q.push(i);
                }
            }/* End of For */
        }
    }/* End of While */
    if (!IsSolved)
        printf("-1\n");
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_2616.txt", "r", stdin);
    freopen("E:\\hdoj_2616_ans.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &n, &totHp))
    {
        for (int i=1; i<=n; ++i)
        {
            hp[i] = totHp;
            hash[i] = false;
            scanf("%d %d", &a[i], &m[i]);
        }/* End of For */
            
        bfs();
    }/* End of While */
    
    return 0;
}

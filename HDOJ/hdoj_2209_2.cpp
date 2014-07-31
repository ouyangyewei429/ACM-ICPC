#include <queue>
#include <cstdio>
#include <memory.h>
using namespace std;

#define onlinejudge

const int maxn = 24;

char bunch[maxn];
bool IsSolved, hash[1<<maxn];
struct Graph
{
    int dig, t;
};

void bfs(int res, int len)
{
    queue <Graph> q;
    struct Graph c, n;
    
    c.dig = res, c.t = 0;
    IsSolved = false, hash[res] = true;
    
    q.push(c);
    while (!q.empty())
    {
        c = q.front();
        q.pop();
        
        if (c.dig == 0)
        {
            IsSolved = true;
            printf("%d\n", c.t);
            break;
        }/* End of IF */
        
        for (int i=0; i<len; ++i)
        {
            n.dig = c.dig;
            n.t = c.t + 1;
            
            if (i == 0)
            {
                n.dig ^= (1<<(len-1));
                if (i+1 < len)
                    n.dig ^= (1<<(len-2));
            }
            else if (i == len-1)
            {
                n.dig ^= 1;
                if (i-1 >= 0)
                    n.dig ^= 2;
            }
            else
            {
                n.dig ^= (1<<(len-i));      // pos i-1
                n.dig ^= (1<<(len-i-1));    // pos i
                n.dig ^= (1<<(len-i-2));    // pos i+1
            }
            
            if (hash[n.dig])
                continue;
            
            hash[n.dig] = true;
            q.push(n);
        }
    }/* End of While */
    if (!IsSolved)
        printf("NO\n");
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_2209.txt", "r", stdin);
    freopen("E:\\hdoj_2209_ans.txt", "w", stdout);
#endif

    while (EOF != scanf("%s", bunch))
    {
        int res=0, len=strlen(bunch);
        memset(hash, false, (1<<len)*sizeof(bool));
        for (int i=0; i<len; ++i)
            res = (res<<1) + (bunch[i]-'0');
        
        if (res == 0)
            printf("0\n");
        else
            bfs(res, len);
    }/* End of While */
    
    return 0;
}

#include <queue>
#include <cstdio>
#include <memory.h>
using namespace std;

#define onlinejudge

const int maxn = 24;

char bunch[maxn];
int  ha[1<<maxn], graph[1<<maxn];
struct Graph
{
    int dig, t;
};

int bfs(int res, int len)
{
    queue <Graph> q;
    struct Graph c, n;
    
    c.dig = res, c.t = 0;
    ha[res] = 1, graph[res] = 0;
    q.push(c);
    
    c.dig = 0, c.t = 0;
    ha[0] = 2, graph[0] = 0;
    q.push(c);
    
    while (!q.empty())
    {
        c = q.front();
        q.pop();
        
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
            
            if (!ha[n.dig])
            {
                graph[n.dig] = c.t + 1;
                ha[n.dig] = ha[c.dig];
                q.push(n);
            }
            else if (ha[c.dig] != ha[n.dig])
            {
                return n.t+graph[c.t];
            }
        }/* End of For */
    }/* End of While */
    
    return -1;
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_2209.txt", "r", stdin);
    freopen("E:\\hdoj_2209_ans_1.txt", "w", stdout);
#endif

    while (EOF != scanf("%s", bunch))
    {
        int res=0, len=strlen(bunch);
        memset(ha, 0, (1<<len)*sizeof(int));
        memset(graph, 0, (1<<len)*sizeof(int));
        for (int i=0; i<len; ++i)
            res = (res<<1) + (bunch[i]-'0');
        
        if (res == 0)
            printf("0\n");
        else
        {
            int ans = bfs(res, len);
            if (ans == -1)
                printf("NO\n");
            else
                printf("%d\n", ans);
        }    
    }/* End of While */
    
    return 0;
}

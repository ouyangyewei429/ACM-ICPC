#include <queue>
#include <cstdio>
#include <cstring>
#include <memory.h>
using namespace std;

const int maxn = 24;

char bunch[maxn];
bool IsSolved, hash[1<<maxn];
struct Graph
{
    char str[maxn];
    int  dig, t;
};

int stod(int n, char s[])
{
    int sum = 0;
    for (int i=0; i<n; ++i)
        sum += (s[n-i-1]-'0')*(1<<i);
    
    return sum;
}/* stod */

void bfs(int len, char s[])
{
    queue <Graph> q;
    struct Graph c, n;
    
    c.t = 0;
    strcpy(c.str, s);
    c.dig = stod(len, bunch);
    hash[c.dig] = true;
    
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
        }/* End of If */
        
        for (int i=0; i<len; ++i)
        {
            n.dig = c.dig;
            n.t = c.t + 1;
            strcpy(n.str, c.str);
            
            if (i-1 >= 0)
            {   // change left bit
                n.str[i-1] = !(c.str[i-1]-'0')+'0';
                if (n.str[i-1]-'0')
                    n.dig += (1<<(len-i));
                else
                    n.dig -= (1<<(len-i));
            }    
            if (i+1 <= len-1)
            {   // change right bit
                n.str[i+1] = !(c.str[i+1]-'0')+'0';
                if (n.str[i+1]-'0')
                    n.dig += (1<<(len-i-2));
                else
                    n.dig -= (1<<(len-i-2));
            }
                
            n.str[i] = !(c.str[i]-'0')+'0';
            if (n.str[i]-'0')
                n.dig += (1<<(len-i-1));
            else
                n.dig -= (1<<(len-i-1));
            
            if (!hash[n.dig])
            {
                hash[n.dig] = true;
                q.push(n);
            }
        }
    }/* End of While */
    if (!IsSolved)
        printf("NO\n");
}/* bfs */

int main()
{
    while (EOF != scanf("%s", bunch))
    {
        int len = strlen(bunch);
        //memset(hash, false, (1<<(len-1))*sizeof(bool));
        for (int i=0; i<=(1<<(len-1)); ++i)
            hash[i] = false;
        
        IsSolved = false;
        bfs(len, bunch);
    }/* End of While */
    
    return 0;
}

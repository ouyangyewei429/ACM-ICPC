/*
PROG:   ∑≠÷Ω≈∆”Œœ∑
ID  :   ouyangyewei
LANG:   C++
*/
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
using namespace std;

//#define onlinejudge

bool hash[1<<20];
char card[24];
typedef struct node
{
    int t, fig; 
}NODE;

int trans(char ss[], int slen)
{
    int ret = 0;
    for (int i=0; i<=slen; ++i)
        ret = (ret<<1) + (ss[i]-'0');
    
    return ret;
}/* trans */

void bbfs(int slen)
{
    NODE c, n;
    bool IsSolved=false;
    queue <NODE> q;
    
    c.t=0, c.fig=trans(card, slen);
    hash[c.fig] = true;
    q.push(c);
    
    while (!q.empty())
    {
        c = q.front();
        q.pop();
        
        if (c.fig == 0)
        {
            IsSolved = true;
            printf("%d\n", c.t);
            break;
        }/* End of IF */
        
        for (int i=0; i<=slen; ++i)
        {
            n.fig = c.fig;
            if (i == 0)
                n.fig^=(1<<slen), n.fig^=(1<<(slen-1));
            else if (i == slen)
                n.fig^=1, n.fig^=2;
            else
                n.fig^=(1<<(slen-i+1)), n.fig^=(1<<(slen-i)), n.fig^=(1<<(slen-i-1));
            
            if (hash[n.fig])
                continue;
            
            n.t = c.t + 1;
            hash[n.fig] = true;
            q.push(n);
        }/* End of For */
    }/* End of While */
    if (!IsSolved)
        printf("NO\n");
    
    return ;
}/* bbfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_2209.txt", "r", stdin);
    freopen("E:\\hdoj_2209_ans.txt", "w", stdout);
#endif

    while (EOF != scanf("%s", card))
    {
        memset(hash, false, sizeof(hash));
        
        bbfs(strlen(card)-1);
    }/* End of While */
    
    return 0;
}

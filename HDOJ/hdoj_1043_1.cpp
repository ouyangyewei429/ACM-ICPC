#include <queue>
#include <stdio.h>
#include <string.h>
#include <memory.h>
using namespace std;

#define onlinejudge

const int maxn = 10;
const int size = 400096;
const char goal[] = "123456789";

bool IsSolved, hash[size];
char bunch[5], puzzle[maxn];
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
int  fac[] = {1, 1, 2, 6, 24, 120, 720, 720*7, 720*56};   /* cantor */
struct Graph
{
    char a[maxn];
    int  xp, ct;
};
struct pn
{
    int cmd, ct;
}path[size];

bool IsOut(int x, int y)
{
	return (x<0 || y<0 || x>=3 || y>=3);
}/* IsOut */

int inver(char s[])
{
    int ret = 0;
    for (int i=0; i<8; ++i)
    {
        if (s[i]=='9')  continue;
        for (int j=i+1; j<9; ++j)
            if (s[j]!='9' && s[j]<s[i]) ret = 1-ret;
    }
    
    return ret;
}/* inver */

int cantor(char s[])
{
    int cnt, res=0;
    for (int i=0; i<8; ++i)
    {
        cnt = 0;
        for (int j=i+1; j<9; ++j)
            if (s[j]<s[i])   ++cnt;

        res += fac[8-i]*cnt;
    }/* End of For */
    
    return res;
}/* cantor */

void dfs(int fp, int ct, int cmd)
{
    if (ct != fp)
        dfs(fp, path[ct].ct, path[ct].cmd);
    
    switch (cmd)
    {
        case 0: printf("u"); break;
        case 1: printf("d"); break;
        case 2: printf("l"); break;
        case 3: printf("r"); break;
    }
}/* dfs */

void bfs(int xpos)
{
    int fp;
    queue <Graph> q;
    struct Graph c, n;
    
    c.xp = xpos;
    memcpy(c.a, puzzle, sizeof(puzzle));
    fp = c.ct = cantor(c.a);
    
    hash[c.ct] = true;
    q.push(c);
    while (!q.empty())
    {
        c = q.front();
        q.pop();
        
        //-------------------------------------------------
        //printf("%s %d %d %d\n", c.a, c.xp, c.ct, path[c.ct].cmd);
        
        if (memcmp(c.a, goal, sizeof(c.a))==0)
        {
            IsSolved = true;
            dfs(fp, c.ct, path[c.ct].cmd);
            printf("\n");
            return ;
        }/* End of IF */
        
        for (int i=0; i<4; ++i)
        {
            int rw = c.xp/3;
            int cl = c.xp%3;
            int nr = rw + dx[i];
            int nc = cl + dy[i];
            
            if (IsOut(nr, nc))  continue;
            
            n.xp = nr*3+nc;
            memcpy(n.a, c.a, sizeof(c.a));
            n.a[c.xp] = c.a[n.xp];
            n.a[n.xp] = c.a[c.xp];
            n.ct = cantor(n.a);
            
            if (hash[n.ct]) continue;
            
            path[n.ct].cmd = i;
            path[n.ct].ct = c.ct;
            hash[n.ct] = true;
            
            q.push(n);
        }/* End of For */
    }/* End of While */
    if (!IsSolved)
        printf("unsolvable\n");
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1043.txt", "r", stdin);
    freopen("E:\\hdoj_1043_ans.txt", "w", stdout);
#endif

    while (EOF != scanf("%s", bunch))
    {
        memset(hash, false, sizeof(hash));
        
        int i, j, sp;
        
        puzzle[0] = (bunch[0]!='x') ? bunch[0]:'9';
        for (i=1; i<9; ++i)
        {
            scanf("%s", bunch);
            puzzle[i] = (bunch[0]!='x') ? bunch[0]:'9';
            if (bunch[0] == 'x')    sp = i;
        }/* End of For */
        
        for (j=0; puzzle[j]==goal[j]&&j<9; ++j);
        if (j == 9)
            printf("\n");
        else if (inver(puzzle) != 0)
            printf("unsolvable\n");
        else
        {
            IsSolved = false;
            bfs(sp);
        }
    }/* End of While */
    
    return 0;
}

#include <queue>
#include <stdio.h>
#include <string.h>
#include <memory.h>
using namespace std;

#define onlinejudge

const int maxn = 10;
const int target = 0x00001FE;

char mat[maxn+50];
bool IsSolved, hash[1<<maxn];
int  dx[] = {-1, 1, 0, 0};
int  dy[] = {0, 0, -1, 1};
struct Graph
{
    int cmd, s, k;
};

struct GraphPath
{
    int d, v;
}path[1<<maxn];

bool IsOut(int x, int y)
{
	return (x<0 || y<0 || x>=3 || y>=3);
}/* IsOut */

void dfs(int os, int cs, int order)
{
    if (path[cs].v != os)
        dfs(os, path[cs].v, path[cs].d);
    
    switch (order)
    {
        case 0: printf("u"); break;
        case 1: printf("d"); break;
        case 2: printf("l"); break;
        case 3: printf("r"); break;
    }
    
    return ;
}/* dfs */

void bfs(int state, int pos)
{
    queue <Graph> q;
    struct Graph c, n;
    
    c.cmd=-1, c.s=state, c.k=pos;
    hash[state] = true;
    
    q.push(c);
    while (!q.empty())
    {
        c = q.front();
        q.pop();
        
        //-----------------------------
        //printf("%d %d %d\n", c.cmd, c.s, c.k);
        
        if (c.s == target)
        {
            IsSolved = true;
            //dfs(state, c.s, c.cmd);
            printf("\n");
            return ;
        }/* End of IF */
        
        for (int i=0; i<4; ++i)
        {
            int nr = c.k/3 + dx[i];
            int nc = c.k%3 + dy[i];

			if (IsOut(nr, nc))
				continue;
            
			n.s = c.s, n.k = nr*3 + nc;
            n.s ^= (1<<(8-c.k));
			n.s ^= (1<<(8-n.k));
            
            if (hash[n.s])
                continue;
            
            n.cmd = i, hash[n.s] = true;
            path[n.s].d = i, path[n.s].v = c.s;
            q.push(n);
        }/* End of For */
    }/* End of While */
    if (!IsSolved)
        printf("unsolvable\n");
    
    return ;
}/* bfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1043.txt", "r", stdin);
    freopen("E:\\hdoj_1043_ans.txt", "w", stdout);
#endif

    while (gets(mat))
    {
        memset(hash, false, sizeof(hash));
        memset(path, 0, sizeof(path));
        
        int cnt=0, st=0, xpos;
        for (int i=0; i<strlen(mat); ++i)
        {
            if (mat[i] != ' ')
            {
                if (mat[i] == 'x')
                    xpos=cnt, st=st<<1;
                else
                    cnt++, st=(st<<1)+1;
            }
        }/* End of For */
        
        IsSolved = false;
        bfs(st, xpos);
    }/* End of While */
    
    //getchar();
    return 0;
}

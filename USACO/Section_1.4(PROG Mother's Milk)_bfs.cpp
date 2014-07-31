/*
PROG:   milk3
ID  :   ouyangyewei
LANG:   C++
*/
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>
#include <algorithm>
using namespace std;

const int maxn = 24;

int  A, B, C;
vector <int> result;
bool hash[maxn][maxn][maxn];
typedef struct node
{
    int a, b, c;
}NODE;

void bfs()
{
    NODE    c, n;
    queue <NODE> q;
    
    c.a=0, c.b=0, c.c=C;    /* The Initial Node */
    hash[0][0][C] = true;
    
    q.push(c);
    while (!q.empty())
    {
        c = q.front();
        q.pop();
        
        if (c.a == 0)
        {
            result.push_back(c.c);
        }/* destin.ation */
    
        if (c.a != 0)
        {
            // Pour(A, B);
            n.b = (c.a+c.b)>=B ? B:(c.a+c.b);
            n.a = c.a+c.b-n.b, n.c=c.c;
            if (!hash[n.a][n.b][n.c])
            {
                hash[n.a][n.b][n.c] = true;
                q.push(n);
            }
            
            // Pour(A, C)
            n.c = (c.a+c.c)>=C ? C:(c.a+c.c);
            n.a = c.a+c.c-n.c, n.b=c.b;
            if (!hash[n.a][n.b][n.c])
            {
                hash[n.a][n.b][n.c] = true;
                q.push(n);
            }
        }
        if (c.b != 0)
        {
            // Pour(B, C)
            n.c = (c.b+c.c)>=C ? C:(c.b+c.c);
            n.b = c.b+c.c-n.c, n.a=c.a;
            if (!hash[n.a][n.b][n.c])
            {
                hash[n.a][n.b][n.c] = true;
                q.push(n);
            }
            
            // Pour(B, A)
            n.a = (c.a+c.b)>=A ? A:(c.a+c.b);
            n.b = c.a+c.b-n.a, n.c=c.c;
            if (!hash[n.a][n.b][n.c])
            {
                hash[n.a][n.b][n.c] = true;
                q.push(n);
            }
        }    
        if (c.c != 0)
        {
            // Pour(C, A)
            n.a = (c.a+c.c)>=A ? A:(c.a+c.c);
            n.c = c.a+c.c-n.a, n.b=c.b;
            if (!hash[n.a][n.b][n.c])
            {
                hash[n.a][n.b][n.c] = true;
                q.push(n);
            }
            
            // Pour(C, B)
            n.b = (c.b+c.c)>=B ? B:(c.b+c.c);
            n.c = c.c+c.b-n.b, n.a=c.a;
            if (!hash[n.a][n.b][n.c])
            {
                hash[n.a][n.b][n.c] = true;
                q.push(n);
            }
        }
    }/* End of While */
}/* bfs */

int main()
{
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);

    while (~scanf("%d %d %d", &A, &B, &C))
    {
        result.clear();     /* Clear the verctor */
        memset(hash, false, sizeof(hash));
        
        bfs();
        sort(result.begin(), result.end());     /* Sort in ascending order */
        for (int i=0; i<result.size(); ++i)
            printf(i==0 ? "%d":" %d", result[i]);
        printf("\n");
    }/* End of While */
    
    return 0;
}

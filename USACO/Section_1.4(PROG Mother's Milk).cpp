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

vector <int> result;
int  A, B, C, cnt;
bool hash[maxn][maxn][maxn];

void dfs(int ca, int cb, int cc)
{
    if (ca == 0)
    {
        result.push_back(cc);
        return ;
    }/* destination */
    
    int na, nb, nc;
    
    // Pour(A, B);
    nb = (ca+cb)>=B ? B:(ca+cb);
    na = ca+cb-nb, nc=cc;
    if (!hash[na][nb][nc])
    {
        hash[na][nb][nc] = true;
        dfs(na, nb, nc);
        hash[na][nb][nc] = false;
    }
    
    // Pour(A, C)
    nc = (ca+cc)>=C ? C:(ca+cc);
    na = ca+cc-nc, nb=cb;
    if (!hash[na][nb][nc])
    {
        hash[na][nb][nc] = true;
        dfs(na, nb, nc);
        hash[na][nb][nc] = false;
    }
    
    // Pour(B, C)
    nc = (cb+cc)>=C ? C:(cb+cc);
    nb = cb+cc-nc, na=ca;
    if (!hash[na][nb][nc])
    {
        hash[na][nb][nc] = true;
        dfs(na, nb, nc);
        hash[na][nb][nc] = false;
    }
    
    // Pour(B, A)
    na = (ca+cb)>=A ? A:(ca+cb);
    nb = ca+cb-na, nc=cc;
    if (!hash[na][nb][nc])
    {
        hash[na][nb][nc] = true;
        dfs(na, nb, nc);
        hash[na][nb][nc] = false;
    }
    
    // Pour(C, A)
    na = (ca+cc)>=A ? A:(ca+cc);
    nc = ca+cc-na, nb=cb;
    if (!hash[na][nb][nc])
    {
        hash[na][nb][nc] = true;
        dfs(na, nb, nc);
        hash[na][nb][nc] = false;
    }
    
    // Pour(C, B)
    nb = (cb+cc)>=B ? B:(cb+cc);
    nc = cc+cb-nb, na=ca;
    if (!hash[na][nb][nc])
    {
        hash[na][nb][nc] = true;
        dfs(na, nb, nc);
        hash[na][nb][nc] = false;
    }
}/* dfs */

int main()
{
    while (~scanf("%d %d %d", &A, &B, &C))
    {
        result.clear();
        memset(hash, false, sizeof(hash));
        
        cnt = 0;
        dfs(0, 0, C);
        
        sort(result.begin(), result.end());
        for (int i=0; i<result.size(); ++i)
            printf(i==0 ? "%d":" %d", result[i]);
        printf("\n");
    }/* End of While */
    
    return 0;
}

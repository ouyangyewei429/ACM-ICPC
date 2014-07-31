/*
PORG:   Ð¡Ï£µÄÃÔ¹¬
ID  :   ouyangyewei
LANG:   C++
*/
#include <set>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
using namespace std;

#define onlinejudge

const int maxn = 100004;

bool hash[maxn], IsEnd=false;
int a, b, i, num, set_num, vertex, edges, room[maxn];

int FindSet(int x)
{
    int k = x;
    while (k != room[k])
        k = room[k];
    
    return k;
}/* FindSet */

void Merge(int x, int y)
{
    int r1 = FindSet(x);
    int r2 = FindSet(y);
    
    if (r1 == r2)
        return ;
    
    if (r1 < r2)
        room[r2] = r1;
    else
        room[r1] = r2;
        
    return ;
}/* Merge */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_1272.txt", "r", stdin);
    freopen("E:\\hdoj_1272_ans.txt", "w", stdout);
#endif

    while (!IsEnd)
    {
        memset(hash, false, sizeof(hash));
        for (i=1; i<=maxn; ++i)
            room[i] = i;
        
        
    }/* End of While */
    
    return 0;
}

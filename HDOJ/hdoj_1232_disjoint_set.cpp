/*
PROG:   ³©Í¨¹¤³Ì
ID  :   ouyangyewei
LANG:   C++
*/
#include <set>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
using namespace std;

const int maxn = 1004;

int i, N, M, a, b, city[maxn];

int FindSet(int x)
{
    int k = city[x];
    while (k != city[k])
        k = city[k];
    
    return k;
}/* FindSet */

void Merge(int x, int y)
{
    int r1 = FindSet(x);
    int r2 = FindSet(y);
    
    if (r1 == r2)
        return ;
    
    if (r1 < r2)
        city[r2] = r1;
    else
        city[r1] = r2;
    
    return ;
}/* Merge */

int main()
{
    while (~scanf("%d", &N), N!=0)
    {
        for (i=1; i<=N; ++i)
            city[i] = i;    // initialize
        
        scanf("%d", &M);
        for (i=1; i<=M; ++i)
        {
            scanf("%d %d", &a, &b);
            Merge(a, b);
        }// disjoint_set */
        
        //set <int> result;
        int cnt = 0;
        for (i=1; i<=N; ++i)
        {
            //result.insert(city[i]);
            if (i == FindSet(i))
                ++cnt;  // Find the number of set
        }    
        printf("%d\n", cnt-1);
        //printf("%d\n", result.size()-1);
    }/* End of While */
    
    return 0;
}

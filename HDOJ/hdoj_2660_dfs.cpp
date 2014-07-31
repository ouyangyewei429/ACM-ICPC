/*
PROG:   Accepted Necklace
ID  :   ouyangyewei
LANG:   C++
*/
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
using namespace std;

const int maxn = 24;

bool hash[maxn];
int  T, N, K, W, result;
typedef struct node
{
    int v, w;
}NODE;
NODE    stone[maxn];

inline int compare(NODE c, NODE d)
{
    if (c.v == d.v)
        return c.w<d.w;
    else
        return c.v>d.v;
}/* compare */

void dfs(int cnt, int used, int cur_value, int cur_weight)
{
    if (cnt==N || cur_weight>W)
        return ;
        
    if (used == K)
    {
        if (cur_value > result)
            result = cur_value;
        return ;
    }/* destination */
    
    dfs(cnt+1, used+1, cur_value+stone[cnt].v, cur_weight+stone[cnt].w);
    dfs(cnt+1, used, cur_value, cur_weight);
}/* dfs */

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &N, &K);
        for (int i=0; i<N; ++i)
        {
            hash[i] = false;
            scanf("%d %d", &stone[i].v, &stone[i].w);
        }/* preprocess */
        scanf("%d", &W);
        
        //sort(stone, stone+N, compare);
        
        result = -1;
        dfs(0, 0, 0, 0);  /* stone_number, used_stone_number, cur_value, cur_weight */
        printf("%d\n", result);
        /*
        for (int i=0; i<N; ++i)
            printf("%d %d\n", data[i].v, data[i].w);
        */
    }/* End of While */
    
    return 0;
}

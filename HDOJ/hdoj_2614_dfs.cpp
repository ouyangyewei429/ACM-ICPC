/*
PROG:   Beat
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <memory.h>
using namespace std;

const int maxn = 16;

bool hash[maxn];
int  N, result, graph[maxn][maxn];

void dfs(int cnt, int st, int costs)
{
    if (result < cnt)
        result = cnt;
    
    for (int i=1; i<N; ++i)
    {
        if (!hash[i] && graph[st][i]>=costs)
        {
            hash[i] = true;
            dfs(cnt+1, i, graph[st][i]);
            hash[i] = false;
        }    
    }/* End of For */
}/* dfs */

int main()
{
    while (~scanf("%d", &N))
    {
        for (int i=0; i<N; ++i)
        {
            hash[i] = false;
            for (int j=0; j<N; ++j)
                scanf("%d", &graph[i][j]);
        }/* preprocess */
        
        result = 1;
        hash[0] = true;
        dfs(1, 0, 0);  /* Numbers_of_solving_problems, start_point, cost_time */
        
        printf("%d\n", result);
    }/* End of while */
    
    return 0;
}

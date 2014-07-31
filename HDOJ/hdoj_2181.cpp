#include <stdio.h>

//#define onlinejudge

const int maxn = 24;

int  a, b, c, M, cnt, path[maxn]={0};
bool hash[maxn]={false}, graph[maxn][maxn]={false};

void dfs(int s, int n)
{
    if (s==M && n==20)
    {
        printf("%d:  %d", cnt++, M);
        for (int i=1; i<=20; ++i)
            printf(" %d", path[i]);
        printf("\n");
        
        return ;
    }/* End of IF */
    
    for (int i=1; i<=20; ++i)
    {
        if ((n<19&&i==M) || hash[i]
            || graph[s][i]==false || n>20)
            continue;
            
        hash[i]=true, path[n+1]=i;
        dfs(i, n+1);
        hash[i]=false, path[n+1]=0;
    }/* End of For */
}/* dfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj_2181.txt", "r", stdin);
    freopen("E:\\hdoj_2181_ans.txt", "w", stdout);
#endif

    for (int i=1; i<=20; ++i)
    {
        scanf("%d %d %d", &a, &b, &c);
        graph[i][a] = graph[a][i] = true;
        graph[i][b] = graph[b][i] = true;
        graph[i][c] = graph[c][i] = true;
    }/* End of For */
    
    while (~scanf("%d", &M), M!=0)
    {
        cnt = 1;
        dfs(M, 0);   /* start_pos, end_pos, number_of_passed_cities */
    }/* End of While */
}

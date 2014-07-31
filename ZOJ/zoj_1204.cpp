/*
PROG:   Additive equations
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

const int maxn = 35;

bool IsSolved, hash[400];
int  T, N, num[maxn], path[maxn]={0};

inline int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}/* compare */

void dfs(int cnt, int sum, int st)
{
    if (hash[sum])
    {
        IsSolved = true;
        for (int i=0; i<cnt; ++i)
            printf(i==0 ? "%d":"+%d", path[i]);
        printf("=%d\n", sum);
                
        return ;
    }/* Reach to Target */
    
    for (int i=st; i<N; ++i)
    {
        if (!sum && hash[num[i]])
            continue;
        //else
        //{
            path[cnt] = num[i];
            dfs(cnt+1, sum+num[i], i+1);
        //}    
    }/* End of For */    
}/* dfs */

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        memset(hash, false, sizeof(hash));
        
        scanf("%d", &N);
        for (int i=0; i<N; ++i)
            scanf("%d", &num[i]);

        if (N < 3)
        {
            printf("Can't find any equations.\n\n");
            continue;
        }
        
        qsort(num, N, sizeof(num[0]), compare);
        for (int k=2; k<N; ++k)
            hash[num[k]] = true;
        
        IsSolved = false;
        dfs(0, 0, 0);  /* cnt, sum, st */
        if (!IsSolved)
            printf("Can't find any equations.\n\n");
        else
            printf("\n");
    }/* End of While */
    
    return 0;
}

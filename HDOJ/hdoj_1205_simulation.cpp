/*
PROG:   ³ÔÌÇ¹û
ID  :   ouyangyewei
LANG:   C
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

long long sum;
int T, N, i, maxValue, candy;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        for (maxValue=-1, sum=0, i=0; i<N; ++i)
        {
            scanf("%d", &candy);
            sum += candy;
            if (maxValue < candy)   maxValue = candy;
        }/* Main Process */
        
        if (sum-maxValue+1 >= maxValue)
            printf("Yes\n");
        else
            printf("No\n");
    }/* End of while */
    
    return 0;
}

/**
 * PROG: ÕûÊı²ğ·Ö
 */
#include <cstdio>

const int MAX_SIZE = 32;

void dfs(int N, int sum, int iNumber, int result[])
{
    if (N == sum)
    {
        printf("%d = %d", N, result[1]);
        for (int j=2; j<iNumber; ++j)
        {
            printf(" + %d", result[j]);
        }
        printf("\n");

        return ;
    }

    for (int i=N; i>=1; --i)
    {
        if (sum+i<=N && i<=result[iNumber-1])
        {
            result[iNumber] = i;
            dfs(N, sum+i, iNumber+1, result);
        }
    }
}

int main(void)
{
    int N;
    int result[MAX_SIZE] = {0};
    while (~scanf("%d", &N))
    {
        result[0] = N;
        dfs(N, 0, 1, result);
    }// End of While

    return 0;
}

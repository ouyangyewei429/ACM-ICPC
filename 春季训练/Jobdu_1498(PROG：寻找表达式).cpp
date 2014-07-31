/**
 * PROG: —∞’“±Ì¥Ô Ω
 */
#include <cstdio>
#include <cstring>
#include <cctype>

const int MAX_EXPRESSION_LENGTH = 128;

int  g_length;
char szExpression[MAX_EXPRESSION_LENGTH] = {0};

void dfs(int number, int last, int sum)
{
    if (number == g_length+1)
    {
        if (0 == sum)
        {
            printf("1");
            for (int j=0; j<g_length-1; ++j)
            {
                printf("%c%d", szExpression[j], j+2);
            }
            printf("\n");
        }
        return ;
    }

    // add ' '
    int temp = (last > 0 ? number : -number);
    szExpression[number-2] = ' ';
    //szExpression[number] = (number + '0');
    if (number < 10)
    {
        dfs(number+1, last*10+temp, sum+last*10+temp-last);
    }
    else
    {
        dfs(number+1, last*100+temp, sum+last*100+temp-last);
    }

    // add '+'
    szExpression[number-2] = '+';
    //szExpression[number] = (number + '0');
    dfs(number+1, number, sum+number);

    // add '-'
    szExpression[number-2] = '-';
    //szExpression[number] = (number + '0');
    dfs(number+1, -number, sum-number);
}

int main(void)
{
    while (~scanf("%d", &g_length))
    {
        szExpression[0] = '1';
        dfs(2, 1, 1);
    }// end of while
    return 0;
}

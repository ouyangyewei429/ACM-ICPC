#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

__int64  ans;
char strA[20] = {0};
char strB[20] = {0};

__int64 String_To_Int(char str[])
{
    int i;
    __int64 buf = 1;
    __int64 sum = 0;
    
    for (i=strlen(str)-1; i>=0; --i)
    {
        if (str[i]>='0' && str[i]<='9')
        {
            sum += buf*(str[i]-'0');
        }
        else if (str[i]>='A' && str[i]<='F')
        {
            sum += buf*(str[i]-'A'+10);
        }/* End of Else */
        
        buf *= 16;
    }/* End of For */
    if (str[0] == '-')
    {
        sum = -sum;
    }/* End of if */
    
    return sum;
}

void Int_To_Hex(__int64 result)
{
    int top = -1;
    int stack[200] = {0};
    
    /* Decimal to hex */
    while (result)
    {
        stack[++top] = result%16;
        result /= 16;
    }
    
    /* Print the Result */
    while (top != -1)
    {
        if (stack[top] >= 10)
        {
            printf("%c", stack[top--]-10+'A');
        }
        else
        {
            printf("%d", stack[top--]);
        }
    }/* End of while */
    printf("\n");
    
    return ;
}

int main()
{
    while (EOF != scanf("%s %s", strA, strB))
    {
        ans = String_To_Int(strA) + String_To_Int(strB);
        if (ans>=0 && ans<=9)
        {
            printf("%d\n", ans);
        }
        else
        {
            if (ans < 0)
            {
                ans = -ans;
                printf("-");
            }
            Int_To_Hex(ans);
        }     
    }/* End of while */
    
    return 0;
}

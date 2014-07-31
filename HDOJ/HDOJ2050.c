#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int     i, casenum, tempNum;
__int64 ans[10005] = {0, 2, 7, 14, 23};

int main()
{
    for (i=5; i<=10000; ++i)
    {
        ans[i] = (2*i+1)+ans[i-1];
    }/* End of For */
    
    scanf("%d", &casenum);
    while (casenum--)
    {
        scanf("%d", &tempNum);
        printf("%I64d\n", ans[tempNum]);
    }/* End of While */
    
    return 0;
}

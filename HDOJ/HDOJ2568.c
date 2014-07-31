#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int casenum, testnum, result;

int main()
{
    scanf("%d", &casenum);
    while (casenum--)
    {
        scanf("%d", &testnum);
        
        result = 0;
        while (testnum)
        {
            if ((testnum&1)==1)
            {
                ++result;
                --testnum;
            }
            else
            {
                testnum >>= 1;
            }
        }/* End of while */
        
        printf("%d\n", result);
    }/* End of While */
    
    return 0;
}

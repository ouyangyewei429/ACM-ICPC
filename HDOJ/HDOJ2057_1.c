#include <stdio.h>
#include <stdlib.h>

__int64 aNum, bNum;

int main()
{
    while (2 == scanf("%I64X %I64X", &aNum, &bNum))
    {
        aNum += bNum;
        if (aNum < 0)
        {
            aNum = -aNum;
            printf("-%I64X\n", aNum);
        }
        else
        {
            printf("%I64X\n", aNum);
        }
    }/* End of while */
    
    return 0;
}

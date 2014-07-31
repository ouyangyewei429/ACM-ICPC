/**
 * PROG: ÊØĞÎÊı
 */
#include <cstdio>

int main(void)
{
    int number;
    while (~scanf("%d", &number))
    {
        bool isTarget = false;
        if (0 == number/10)
        {
            isTarget = ((number*number)%10 == number);
        }
        else if (0 == number/100)
        {
            isTarget = ((number*number)%100 == number);
        }

        if (isTarget)
        {
            printf("Yes!\n");
        }
        else
        {
            printf("No!\n");
        }
    }// End of while
    return 0;
}

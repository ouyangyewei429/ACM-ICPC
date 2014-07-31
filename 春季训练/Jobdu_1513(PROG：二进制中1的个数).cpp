/**
 * PROG: 二进制中1的个数
 */
#include <cstdio>

int main(void)
{
    int nCases;
    scanf("%d", &nCases);
    while (nCases--)
    {
        unsigned int number;
        scanf("%u", &number);

        int count = 0;
        while (0 != number)
        {
            count += (number & 1);
            number >>= 1;
        }
        printf("%d\n", count);
    }// End of While

    return 0;
}

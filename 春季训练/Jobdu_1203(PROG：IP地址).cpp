/**
 * PROG: IPµÿ÷∑
 */
#include <cstdio>

int main(void)
{
    int nCases;
    scanf("%d", &nCases);
    while (nCases--)
    {
        int a, b, c, d;
        scanf("%d.%d.%d.%d", &a, &b, &c, &d);
        if (a>255 || b>255 || c>255 || d>255 ||
            a<0 || b<0 || c<0 || d<0)
        {
            printf("No!\n");
        }
        else
        {
            printf("Yes!\n");
        }
    }
    return 0;
}

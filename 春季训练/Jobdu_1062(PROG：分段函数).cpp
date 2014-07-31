/**
 * PROG: ·Ö¶Îº¯Êý
 */
#include <cstdio>

int main(void)
{
    double x, y;
    while (~scanf("%lf", &x))
    {
        if (x>=0 && x<2)
        {
            y = 2.5 - x;
        }
        else if (x>=2 && x<4)
        {
            y = 2.0 - 1.5*(x-3.0)*(x-3.0);
        }
        else if (x>=4 && x<6)
        {
            y = x/2.0 - 1.5;
        }
        printf("%.3lf\n", y);
    }
    return 0;
}

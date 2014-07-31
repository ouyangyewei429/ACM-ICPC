/**
 * PROG: abc
 */
#include <cstdio>

int main(void)
{
    for (int a=0; a<=9; ++a)
    {
        for (int b=0; b<=9; ++b)
        {
            for (int c=0; c<=9; ++c)
            {
                int abc = a*100 + b*10 + c;
                int bcc = b*100 + c*10 + c;
                if (532 == abc+bcc)
                {
                    printf("%d %d %d\n", a, b, c);
                }
            }
        }
    }
    return 0;
}

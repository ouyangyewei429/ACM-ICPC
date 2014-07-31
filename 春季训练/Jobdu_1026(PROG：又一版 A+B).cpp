/**
 * PROG: ”÷“ª∞Ê A+B
 */
#include <cstdio>

void CalcScaleBy(int m, long long number)
{
    int length = 0;
    int result[256] = {0};

    while (0 != number)
    {
        result[length++] = number % m;
        number /= m;
    }
    for (int i=length-1; i>=0; --i)
    {
        printf("%d", result[i]);
    }
    printf("\n");
}

int main(void)
{
    int m;
    long long a, b;
    while (~scanf("%d", &m) && 0!=m)
    {
        scanf("%lld %lld", &a, &b);
        if (0 == a+b)
        {
            printf("0\n");
        }
        else
        {
            CalcScaleBy(m, a+b);
        }
    }
    return 0;
}

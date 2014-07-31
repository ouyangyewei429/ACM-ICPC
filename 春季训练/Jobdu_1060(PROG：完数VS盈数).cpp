/**
 * PROG: ÍêÊýVSÓ¯Êý
 */
#include <cstdio>

const int MAX_SIZE = 32;

enum NUMBER_TYPE
{
    E_NONE = 0,
    E_E_NUMBER = 1,
    E_G_NUMBER = 2,
};

NUMBER_TYPE GetNumberType(const int number)
{
    int sum = 0;
    for (int i=1; i<=number/2; ++i)
    {
        if (0 == number%i)
        {
            sum += i;
        }
    }
    if (sum == number)
    {
        return E_E_NUMBER;
    }
    if (sum > number)
    {
        return E_G_NUMBER;
    }
    else
    {
        return E_NONE;
    }
}

int main(void)
{
    int nENum = 0;
    int nGNum = 0;
    int e_number[MAX_SIZE] = {0};
    int g_number[MAX_SIZE] = {0};

    for (int number=2; number<=60; ++number)
    {
        NUMBER_TYPE type = GetNumberType(number);
        if (E_E_NUMBER == type)
        {
            e_number[nENum++] = number;
        }
        if (E_G_NUMBER == type)
        {
            g_number[nGNum++] = number;
        }
    }

    bool isFirstNumber = true;
    for (int i=0; i<nENum; ++i)
    {
        if (!isFirstNumber)
        {
            printf(" %d", e_number[i]);
        }
        else
        {
            isFirstNumber = false;
            printf("E: %d", e_number[i]);
        }
    }
    printf("\n");

    isFirstNumber = true;
    for (int i=0; i<nGNum; ++i)
    {
        if (!isFirstNumber)
        {
            printf(" %d", g_number[i]);
        }
        else
        {
            isFirstNumber = false;
            printf("G: %d", g_number[i]);
        }
    }
    printf("\n");
    return 0;
}

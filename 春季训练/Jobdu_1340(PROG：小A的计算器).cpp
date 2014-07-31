/**
 * PROG: Ð¡AµÄ¼ÆËãÆ÷
 */
#include <cstdio>
#include <cstring>

const int MAX_SIZE = 10;

long long GetNumber(const char szNumber[])
{
    long factor = 1;
    long result = 0;

    int strLen = strlen(szNumber);
    for (int i=strLen-1; i>=0; --i)
    {
        result = result + factor*(szNumber[i]-'a');
        factor *= 26;
    }
    return result;
}

void ConvertToString(long long number)
{
    int  res = 0;
    int  length = 0;
    char szResult[MAX_SIZE] = {0};

    while (0 != number)
    {
        res = number % 26;
        number /= 26;

        szResult[length++] = ('a' + res);
    }
    for (int i=length-1; i>=0; --i)
    {
        printf("%c", szResult[i]);
    }
    printf("\n");
}

int main(void)
{
    int nCases;
    char szNumberA[MAX_SIZE] = {0};
    char szNumberB[MAX_SIZE] = {0};

    scanf("%d", &nCases);
    while (nCases--)
    {
        scanf("%s %s", szNumberA, szNumberB);
        long long number_a = GetNumber(szNumberA);
        long long number_b = GetNumber(szNumberB);
        if (0 == number_a+number_b)
        {
            printf("a\n");
        }
        else
        {
            ConvertToString(number_a + number_b);
        }
        //printf("** %lld %lld **\n", number_a, number_b);
    }// End of While

    return 0;
}

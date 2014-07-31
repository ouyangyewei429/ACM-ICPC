/**
 * PROG: Ğ¡ºï×ÓÏÂÂä
 */
#include <cstdio>

int main(void)
{
    int deep;
    int nMonkeys;
    while (~scanf("%d %d", &deep, &nMonkeys))
    {
        if (0==deep && 0==nMonkeys)
        {
            break;
        }

        int iLeaf = 1;
        for (int i=2; i<=deep; ++i)
        {
            if (nMonkeys & 1)
            {   // odd
                iLeaf <<= 1;
                nMonkeys = (nMonkeys + 1) / 2;
            }
            else
            {   // even
                iLeaf = (iLeaf<<1) + 1;
                nMonkeys >>= 1;
            }
        }
        printf("%d\n", iLeaf);
    }

    return 0;
}

/**
 * PROG: п║╨ОвсоббД
 */
#include <cstdio>
#include <memory.h>

const int MAX_SIZE = 1<<20;

bool g_tree[MAX_SIZE];

int main(void)
{
    int deep, nMonkeys;
    while (~scanf("%d %d", &deep, &nMonkeys))
    {
        if (0==deep && 0==nMonkeys)
        {
            break;
        }

        int iLeaf;
        memset(g_tree, false, sizeof(g_tree));
        for (int i=1; i<=nMonkeys; ++i)
        {
            iLeaf = 1;
            for (int j=2; j<=deep; ++j)
            {
                //printf("**%d**\n", iLeaf);
                if (!g_tree[iLeaf])
                {
                    g_tree[iLeaf] = !g_tree[iLeaf];
                    iLeaf <<= 1;
                }
                else
                {
                    g_tree[iLeaf] = !g_tree[iLeaf];
                    iLeaf = (iLeaf<<1) + 1;
                }
            }
        }
        printf("%d\n", iLeaf);
    }

    return 0;
}

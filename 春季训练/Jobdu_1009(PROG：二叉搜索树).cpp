/**
 * PROG: ¶þ²æËÑË÷Ê÷
 */
#include <cstdio>
#include <cstring>

const int MAX_TREE_LENGTH = 1<<12;
const int MAX_STRING_LENGTH = 16;

int g_tree[MAX_TREE_LENGTH];

void BuildTree(const char* szTree)
{
    memset(g_tree, 0xffffffff, sizeof(g_tree));

    g_tree[1] = szTree[0]-'0';
    int strLen = strlen(szTree);
    for (int i=1; i<strLen; ++i)
    {
        int root = 1;
        int val = szTree[i] - '0';
        while (true)
        {
            if (-1 == g_tree[root])
            {
                //printf("**%d**\n", root);  // debug....................................
                g_tree[root] = val;
                break;
            }
            else if (-1!=g_tree[root] && val<g_tree[root])
            {
                root <<= 1;
            }
            else if (-1!=g_tree[root] && val>=g_tree[root])
            {
                root = (root<<1) + 1;
            }
        }
    }
}

bool IsSameBinaryTree(const char* szTree)
{
    int strLen = strlen(szTree);
    for (int i=0; i<strLen; ++i)
    {
        int root = 1;
        int val = szTree[i] - '0';
        while (true)
        {
            if (val == g_tree[root])
            {
                printf("**val=%d,root=%d,g_tree=%d**\n", val, root, g_tree[root]);  // debug................
                break;
            }
            if (-1 == g_tree[root])
            {
                return false;
            }
            else if (-1!=g_tree[root] && val<g_tree[root])
            {
                root <<= 1;
            }
            else if (-1!=g_tree[root] && val>=g_tree[root])
            {
                root = (root<<1) + 1;
            }
        }
    }
    return true;
}

int main(void)
{
    int nCases;
    char szTree[MAX_STRING_LENGTH] = {0};
    while (~scanf("%d", &nCases))
    {
        if (0 == nCases)
        {
            break;
        }

        scanf("%s", szTree);
        BuildTree(szTree);

        for (int i=0; i<nCases; ++i)
        {
            scanf("%s", szTree);
            if (IsSameBinaryTree(szTree))
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }

    return 0;
}

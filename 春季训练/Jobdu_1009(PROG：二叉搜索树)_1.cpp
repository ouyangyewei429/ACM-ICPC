/**
 * PROG: ¶þ²æËÑË÷Ê÷
 */
#include <cstdio>
#include <cstring>

const int MAX_TREE_LENGTH = 1<<12;
const int MAX_STRING_LENGTH = 16;

int g_origin[MAX_TREE_LENGTH];
int g_compare[MAX_TREE_LENGTH];

void BuildTree(int tree[], const char* szSequence)
{
    for (int i=0; i<MAX_TREE_LENGTH; ++i)
    {
        tree[i] = 0xffffffff;
        //printf("tree = %d\n", tree[i]);
    }
    //memset(tree, 0xffffffff, sizeof(tree));
    tree[1] = szSequence[0] - '0';

    //printf("tree[1] = szSequence[0] - '0';\n");  // debug................................................

    int strLen = strlen(szSequence);
    for (int i=1; i<strLen; ++i)
    {
        int root = 1;
        int val = szSequence[i] - '0';
        while (true)
        {
            if (-1 == tree[root])
            {
                //printf("**%d**\n", root);  // debug...............................
                tree[root] = val;
                break;
            }
            else if (-1!=tree[root] && val<tree[root])
            {
                //printf("**val=%d,root=%d**\n", val, root);  // debug...............................
                root <<= 1;
            }
            else if (-1!=tree[root] && val>=tree[root])
            {
                //printf("**val=%d,root=%d**\n", val, root);  // debug...............................
                root = (root<<1) + 1;
            }
        }
    }
}

bool IsSameBinaryTree(const int strLen)
{
    int nLoops = (1<<strLen);
    for (int i=1; i<=nLoops; ++i)
    {
        if (g_origin[i] != g_compare[i])
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    int nCases;
    char szSequence[MAX_STRING_LENGTH] = {0};
    while (~scanf("%d", &nCases))
    {
        if (0 == nCases)
        {
            break;
        }

        scanf("%s", szSequence);
        BuildTree(g_origin, szSequence);
        for (int i=0; i<nCases; ++i)
        {
            scanf("%s", szSequence);
            BuildTree(g_compare, szSequence);
            if (IsSameBinaryTree(strlen(szSequence)))
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

/**
 * PROG: ¶þ²æÊ÷±éÀú
 */
#include <cstdio>

const int MAX_SIZE = 128;

typedef struct Tree
{
    Tree *lChild;
    Tree *rChild;
    char value;

    Tree(char ch)
    {
        lChild = NULL;
        rChild = NULL;
        value  = ch;
    }
} *TreePtr;

int  g_iBunch = 0;
char g_szBunch[MAX_SIZE] = {0};

void BuildTree(TreePtr& node)
{
    //printf("== %c ==\n", g_szBunch[g_iBunch]);  // debug,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
    if (' '==g_szBunch[g_iBunch] || '#'==g_szBunch[g_iBunch])
    {
        ++g_iBunch;
        return ;
    }
    else if (NULL == node)
    {
        node = new Tree(g_szBunch[g_iBunch++]);
        //printf("*** %c ***\n", node->value);  // debug................................
    }

    BuildTree(node->lChild);
    BuildTree(node->rChild);
}

void InOrderTraver(TreePtr node)
{
    if (NULL != node)
    {
        InOrderTraver(node->lChild);
        printf("%c ", node->value);
        InOrderTraver(node->rChild);
    }
}

void DestructTree(TreePtr& node)
{
    if (NULL != node)
    {
        DestructTree(node->lChild);
        DestructTree(node->rChild);
        //printf("** %c **\n", node->value);
        delete node;
        node = NULL;
    }
}

int main(void)
{
    while (gets(g_szBunch))
    {
        //printf("** %s **\n", g_szBunch);  // debug.................................

        g_iBunch = 0;

        Tree *root = NULL;
        BuildTree(root);
        InOrderTraver(root);
        printf("\n");

        DestructTree(root);
    }// End of While

    return 0;
}

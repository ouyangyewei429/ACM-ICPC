/**
 * PROG: ±È¿˙¡¥±Ì
 */
#include <cstdio>

typedef struct List
{
    int   m_value;
    List* m_next;

    List()
    {
        m_value = 0;
        m_next = NULL;
    }
    List(const int value)
    {
        m_value = value;
        m_next = NULL;
    }
} *ListPtr;

void ListInsert(ListPtr& head, ListPtr& node)
{
    if (NULL == head)
    {   // empty list
        head = node;
    }
    else if (NULL == head->m_next)
    {   // only one node
        if (node->m_value < head->m_value)
        {
            node->m_next = head;
            head = node;
        }
        else
        {
            head->m_next = node;
        }
    }
    else
    {   // more than two nodes
        List *front = head;
        List *back  = head->m_next;
        while (NULL != back)
        {
            if (node->m_value <= head->m_value)
            {
                node->m_next = head;
                head = node;

                break;
            }
            else if (node->m_value > front->m_value &&
				     node->m_value <= back->m_value)
            {
                front->m_next = node;
                node->m_next = back;

                break;
            }

            front = front->m_next;
            back = back->m_next;
        }
        if (NULL == back)
        {
            front->m_next = node;
        }
    }
}

int main(void)
{
    int nNodes;
    while (~scanf("%d", &nNodes))
    {
        List *head = NULL;
        for (int i=0; i<nNodes; ++i)
        {
            List *node = new List();
            scanf("%d", &node->m_value);

            ListInsert(head, node);
        }


        printf("%d", head->m_value);
        List *ptr = head->m_next;
        while (NULL != ptr)
        {
            printf(" %d", ptr->m_value);
            ptr = ptr->m_next;
        }
        printf("\n");
    }
    return 0;
}

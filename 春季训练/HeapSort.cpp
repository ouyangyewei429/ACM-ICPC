/**
 * PROG: Heap Sort
 */
#include <cstdio>

const int MAX_SIZE = 1024;

int g_nNum = 0;
int g_heap[MAX_SIZE] = {0};

/**
 * 调整节点
 * @parent: 传入的父节点
 * 将父节点与其孩子节点进行交换
 */
void ShiftDown(int parent, int n)
{
    int child;
    int key = g_heap[parent];

    for (; parent<=n/2; parent=child)
    {
        child = parent * 2;
        if (child!=n && g_heap[child+1]>=g_heap[child])
        {
            child = child + 1;
        }

        if (g_heap[child] > key)
        {
            g_heap[parent] = g_heap[child];
        }
        else
        {
            break;
        }
    }
    g_heap[parent] = key;
}

void HeapSort()
{
    /**
     * 建立最大堆
     *
     * 调整是从最后一个非叶子结点开始的，
     * 每次选定一个父节点，然后向下调整，
     * g_nNum/2 表示的是最后一个非叶子结点
     */
    for (int parent=g_nNum/2; parent>=1; --parent)
    {
        ShiftDown(parent, g_nNum);
    }

    for (int i=g_nNum; i>=1; --i)
    {
        int temp = g_heap[1];
        g_heap[1] = g_heap[i];
        g_heap[i] = temp;

        ShiftDown(1, i-1);

        printf("===============\n");
        for (int i=1; i<=g_nNum; ++i)
        {
            printf("%d ", g_heap[i]);
        }
        printf("\n");
    }
}

int main(void)
{
    while (~scanf("%d", &g_nNum))
    {
        /**
         * 堆顶是从1开始计数的
         */
        for (int i=1; i<=g_nNum; ++i)
        {
            scanf("%d", &g_heap[i]);
        }

        HeapSort();

        for (int i=1; i<=g_nNum; ++i)
        {
            printf("%d ", g_heap[i]);
        }
        printf("\n");
    }// End of While

    return 0;
}


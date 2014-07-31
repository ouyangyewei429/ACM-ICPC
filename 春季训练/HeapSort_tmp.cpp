#include <stdio.h>

int casenum, nNum, heap[100002];

void shiftdown(int fa, int n)
{
    int son, key=heap[fa];
    for (; fa<=n/2; fa=son)
    {
        son = fa*2;    /* left child */
        if (son!=n && heap[son+1]>heap[son])
            son = son + 1;

        if (heap[son] > key)
            heap[fa] = heap[son];
        else
            break;
    }/* End of For */
    heap[fa] = key;
}/* shiftdown */

void heapSort()
{
    for (int i=nNum>>1; i>=1; --i)
        shiftdown(i, nNum);

    for (int i=nNum; i>=1; --i)
    {
        int swap = heap[1];
        heap[1] = heap[i];
        heap[i] = swap;

        shiftdown(1, i-1);

        printf("===============\n");
        for (int i=1; i<=nNum; ++i)
        {
            printf("%d ", heap[i]);
        }
        printf("\n");
    }/* End of For */
}/* heapSort */

int main()
{
    scanf("%d", &casenum);
    while (casenum--)
    {
        scanf("%d", &nNum);
        for (int i=1; i<=nNum; ++i)
            scanf("%d", &heap[i]);

        heapSort();
        printf("%d", heap[1]);
        for (int i=2; i<=nNum; ++i)
            printf(" %d", heap[i]);
        printf("\n");
    }/* End of While */

    return 0;
}

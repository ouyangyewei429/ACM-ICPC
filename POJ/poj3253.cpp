#include <stdio.h>
#include <memory.h>

#define onlinejudge
#define INF 0x3F3F3F3F

int     nNum;
__int64 sum, heap[20004];

void shiftdown(int fa, int n)
{
    int     son;
    __int64 key=heap[fa];
    for (; fa<=n; )
    {
        son = fa<<1;    /* left_child */
        if (fa!=n && heap[son+1]<heap[son])
            son = son + 1;
        
        if (heap[fa] > heap[son])
        {
            heap[fa] = heap[son];
            fa = son;
            son = fa<<1;
        }
        else
            break;
    }/* End of For */
    heap[fa] = key;
}/* shiftdown */

__int64 GetHeapTop()
{
    __int64 ret = heap[1];
    
    heap[1] = heap[nNum--];
    shiftdown(1, nNum);
    
    return ret;
}/* GetHeapTop */

void InsertElem(__int64 t)
{    
    heap[++nNum] = t;

    int p = nNum;
    while (p>1 && heap[p>>1]>t)
    {
        heap[p] = heap[p>>1];
        p >>= 1;
    }/* End of While */
    heap[p] = t;
}/* InsertElem */

int main()
{
#ifdef onlinejudge
    freopen("E:\\poj3253.txt", "r", stdin);
    freopen("E:\\poj3253_ans.txt", "w", stdout);
#endif

	int i;
    while (~scanf("%d", &nNum))
    {
        /* Initialized */
        memset(heap, INF, sizeof(heap));
        
        sum = 0;
        for (i=1; i<=nNum; ++i)
        {
            scanf("%I64d", &heap[i]);
            sum += heap[i];
        }/* End of For */
        
        /* BulidMinHeap */
        for (i=nNum>>1; i>=1; --i)
            shiftdown(i, nNum);
        
        int mNum = nNum;
        for (i=1; i<mNum-1; ++i)
        {
            __int64 min1 = GetHeapTop();
            __int64 min2 = GetHeapTop();
            
            sum += min1 + min2;
            InsertElem(min1+min2);
        }/* End of For */
        
        printf("%I64d\n", sum);
    }/* End of While */
    
    return 0;
}    

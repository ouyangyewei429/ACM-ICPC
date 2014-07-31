#include <stdio.h>
#include <memory.h>

#define onlinejudge

const int maxn = 20004;
const int INF = 0x3F3F3F3F;

int     nNum;
__int64 heap[maxn];

void shiftdown(int fa, int n)
{
    int		son;
	__int64	key=heap[fa];
    for (; fa<=n>>1; fa=son)
    {
        son = fa<<1;    /* Left_child */
        if (son!=n && heap[son+1]<heap[son])
            son = son +1;
        
        if (key > heap[son])
            heap[fa] = heap[son];
        else
            break;
    }/* End of For */
    heap[fa] = key;
}/* shiftdown */

__int64 GetHeapTop()
{
    __int64 ret = heap[1];
    
    heap[1] = heap[nNum];
	heap[nNum--] = INF;
    shiftdown(1, nNum);
    
    return ret;
}/* GetHeapTop */

void InSertToHeap(int t)
{
    heap[++nNum] = t;
    
    int p = nNum;
    while (p!=1 && heap[p>>1]>t)
    {
        heap[p] = heap[p>>1];
        p >>= 1;
    }/* End of While */
    heap[p] = t;
}/* InSertToHeap */

int main()
{
#ifdef onlinejudge
    freopen("E:\\poj3253.txt", "r", stdin);
    freopen("E:\\poj3253_ans.txt", "w", stdout);
#endif

	int i;
    while (~scanf("%d", &nNum))
    {
        /** Initialized
        for (i=1; i<=(nNum<<1|1); ++i)
            heap[i] = INF;
        ***/
        
        memset(heap, INF, sizeof(heap));
        
        /* Input */
        for (i=1; i<=nNum; ++i)
            scanf("%I64d", &heap[i]);
        
        /* Build the Min_Heap */
        for (i=nNum>>1; i>=1; --i)
            shiftdown(i, nNum);
            
        __int64 a, b, lowcost = 0;
        while (nNum > 1)
        {
            a = GetHeapTop();
            b = GetHeapTop();
            
            lowcost += a+b;
            InSertToHeap(a+b);
        }/* End of While */
        
        printf("%I64d\n", lowcost);
    }/* End of While */
    
    return 0;
}


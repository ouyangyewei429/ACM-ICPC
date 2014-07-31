#include <stdio.h>
#include <memory.h>

#define onlinejudge

const int maxn = 1000010;
const int INF  = 0x3F3F3F3F;

char ch;
int  casenum, kNum, cnt, num, heap[maxn];

void shiftdown(int fa, int n)
{
    int	son, key=heap[fa];
    for (; fa<=n>>1; fa=son)
    {
        son = fa<<1;    /* Left_child */
        if (son!=n && heap[son+1]<heap[son])
            son = son + 1;
        
        if (key > heap[son])
            heap[fa] = heap[son];
        else
            break;
    }/* End of For */
    heap[fa] = key;
}/* shiftdown */

void InsertHeap(int t)
{
    heap[++cnt] = t;
    
    int p = cnt;
    while (p!=1 && heap[p>>1]>t)
    {
        heap[p] = heap[p>>1];
        p >>= 1;
    }/* End of While */
    heap[p] = t;
}/* InsertHeap */

void PopHeadTop(int t)
{
    heap[1] = t;
    shiftdown(1, cnt);
}/* PopHeadTop */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj4006.txt", "r", stdin);
    freopen("E:\\hdoj4006_ans.txt", "w", stdout);
#endif

    while (~scanf("%d %d", &casenum, &kNum))
    {
        memset(heap, INF, sizeof(heap));
        
        cnt = 0;
        for (int i=1; i<=casenum; ++i)
        {
            getchar();
            scanf("%c", &ch);
            if (ch == 'I')
            {
                scanf("%d", &num);
                if (cnt < kNum)
                {
                    InsertHeap(num);
                }
                else if (num > heap[1])
                {
                    PopHeadTop(num);
                }
            }
            else
            {
                printf("%d\n", heap[1]);
            }
        }/* End of For */
    }/* End of While */
    
    return 0;
}

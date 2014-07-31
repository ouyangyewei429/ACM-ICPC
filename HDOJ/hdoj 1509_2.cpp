#include <stdio.h>
#include <string.h>

const int maxn = 60049;

struct Message
{
    int w, argu;
    char meg[1010];
}heap[maxn];

int  cnt=0;
char cmd[10];

void swap(int x, int y)
{
    struct Message tmp = heap[x];
    heap[x] = heap[y];
    heap[y] = tmp;
}/* swap */

void shiftdown(int k, int n)
{
    int son;
    struct Message key = heap[n];
    
    for (; k<=n>>1; k=son)
    {
        son = k>>1;
        if (k!=n && heap[son+1].w)
    }/* End of For */
}

void GetHeapTop()
{
    printf("%s %d\n", heap[1].meg, heap[1].argu);
    
    swap(1, cntn);
    shiftdown(1, --cnt);
}/* GetHeapTop */

int main()
{
    while (~scanf("%s", cmd))
    {
        if (cmd[0] == 'G')
        {
            if (cnt == 0)
                printf("EMPTY QUEUE!\n");
            else
                GetHeapTop();
        }
    }/* End of While */
    
    return 0;
}

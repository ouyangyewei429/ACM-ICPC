#include <stdio.h>
#include <string.h>

//#define onlinejudge

const int maxn = 60004;
const int INF  = 0x3F3F3F3F;

struct MesQueue
{
    int  argu, w, num;
    char meg[10];
}heap[maxn];

int  n=0, cnt=0;
char cmd[10];

bool cmp(struct MesQueue x, struct MesQueue y)
{
    if (x.w == y.w)
        return (x.num>y.num ? 1:0);
    else
        return (x.w>y.w ? 1:0);
}/* cmp */

void shiftdown(int k, int n)    /* From top to bottom */
{
    int son;
    struct MesQueue key = heap[k];  /* key=heap[k].w */
    
    for (; k<=n>>1; k=son)
    {
        son = k<<1;
        if (k!=n && cmp(heap[son], heap[son+1]))
            son = son + 1;
        
        if (cmp(key, heap[son]))
            heap[k] = heap[son]; 
        else
            break;
    }/* End of For */
    heap[k] = key;
}/* shiftdown */

void GetHeapTop()
{
    printf("%s %d\n", heap[1].meg, heap[1].argu);
    
    heap[1] = heap[n];
    
    heap[n].w = INF;
    heap[n].num = 0;
    heap[n].argu = 0;
    strcpy(heap[n].meg, "\0");

    shiftdown(1, --n);
}/* GetHeapTop */

void InsertHeap()
{
    ++n;    /* number of node in heap increase one */
    ++cnt;  /* Mark of node in heap */
    
    scanf("%s %d %d", &heap[n].meg, &heap[n].argu, &heap[n].w);
    heap[n].num = cnt;
    
    int p = n; /* heap[p>>1].w>tmp.w */
    struct MesQueue tmp = heap[n];
    
    while (p!=1 && cmp(heap[p>>1], tmp))    /* From bottom to top */
    {
        heap[p] = heap[p>>1];
        p >>= 1;
    }/* End of While */
    heap[p] = tmp;
}/* InsertHeap */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj1509_1.txt", "r", stdin);
	freopen("E:\\hdoj1509_1_ans.txt", "w", stdout);
#endif

    while (~scanf("%s", cmd))
    {
        if (cmd[0] == 'G')
        {   /* GET */
            if (n == 0)
                printf("EMPTY QUEUE!\n");
            else
                GetHeapTop();
        }/* End of IF */
        else
        {
            InsertHeap();
        }
    }/* End of While */
    
    return 0;
}

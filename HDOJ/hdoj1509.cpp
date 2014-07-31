#include <stdio.h>
#include <string.h>
#include <memory.h>

#define onlinejudge

const int maxn = 60024;
const int INF  = 0x3F3F3F3F;

char cmd[6]={0}, bunch[100]={0};
int  pNum, rNum, cnt=0;

struct MEG
{
    int  para, rank;
    char message[100];
}heap[maxn];

void shiftdown(int fa, int n)
{
    int  son;
    char tempMessage[100] = {0};
    int  tempPara = heap[fa].para;
    int  tempRank = heap[fa].rank;
    
    strcpy(tempMessage, heap[fa].message);
    for (; fa<=n>>1; fa=son)
    {
        son = fa<<1;    /* Left_Child */
        if (fa!=n && heap[son+1].rank<heap[son].rank)
            son = son + 1;
        
        if (tempRank > heap[son].rank)
        {
            heap[fa].para = heap[son].para;
            heap[fa].rank = heap[son].rank;
            strcpy(heap[fa].message, heap[son].message);
        }
        else
            break;
    }/* End of For */
    
    heap[fa].para = tempPara;
    heap[fa].rank = tempRank;
    strcpy(heap[fa].message, tempMessage);
}/* shiftdown */

void GetHeapTop()
{
    /* change the heap top into heap tail */
    heap[1].para = heap[cnt].para;
    heap[1].rank = heap[cnt].rank;
    strcpy(heap[1].message, heap[cnt].message);
    
    /* change the tail */
    heap[cnt].para = 0;
    heap[cnt].rank = INF;
    strcpy(heap[cnt].message, "\0");
    
    --cnt;  /* Len - 1 */
    shiftdown(1, cnt);  /* Adjust */
}/* GetHeapTop */

void InsertHeapTop(char s[], int pa, int r)
{
    ++cnt;  /* Len + 1 */
    heap[cnt].para = pa;
    heap[cnt].rank = r;
    strcpy(heap[cnt].message, s);
    
    int p = cnt;
    while (p!=1 && heap[p>>1].rank>r)
    {
        heap[p].para = heap[p>>1].para;
        heap[p].rank = heap[p>>1].rank;
        strcpy(heap[p].message, heap[p>>1].message);
        
        p >>= 1;
    }/* End of While */
    
    heap[p].para = pa;
    heap[p].rank = r;
    strcpy(heap[p].message, s);
}/* InsertHeapTop */

int main()
{
#ifdef onlinejudge
    freopen("E:\\hdoj1509.txt", "r", stdin);
    freopen("E:\\hdoj1509_ans.txt", "w", stdout);
#endif

    for (int i=1; i<=60004; ++i)
    {
        heap[i].para = 0;
        heap[i].rank = INF;
        strcpy(heap[i].message, "\0");
    }/* End of For */
    
    while (~scanf("%s", cmd))
    {
        if (strcmp(cmd, "GET") == 0)
        {   /* Get the Elem of the highest priority */
            if (cnt == 0)
                printf("EMPTY QUEUE!\n");
            else
            {
                printf("%s %d\n", heap[1].message, heap[1].para);
                GetHeapTop();
            }
        }/* End of IF */
        else
        {   /* InSert the Elem into heap according to it's priority */
            scanf("%s %d %d", bunch, &pNum, &rNum);
            InsertHeapTop(bunch, pNum, rNum);
        }
    }/* End of While */
    
    return 0;
}

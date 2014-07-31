/*
PROG:   Flo's Restaurant
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>

#define DEBUG 0

const int maxn = 10000040;
const int INF = 0x3F3F3F3F;

char buf[104];
int  sum, hSize;
struct restaurant
{
    int ss, tt;
    restaurant *next;
}*List[3];
struct HEAP
{
    int st, et, groups;
}heap[maxn];
/*
bool ReadLine(char *s)
{
    int L;
    for ( L=0; ( s[L]=getchar() )!='\n' && s[L]!=EOF; ++L )
    s[L] = '\0';
    
    return ( buf[0]=='#' ? true:false );
}// ReadLine
*/
void Creat_Adjacent_Table(int x, int y, int z)
{
	int i;
    restaurant *temp = NULL;
    
    memset( List, 0, sizeof(List) );
    for (i=0; i<x; ++i)
    {
        temp = new restaurant;
        temp->ss = temp->tt = 0;
        temp->next = List[0], List[0] = temp;
    }
    for (i=0; i<y; ++i)
    {
        temp = new restaurant;
        temp->ss = temp->tt = 0;
        temp->next = List[1], List[1] = temp;
    }
    for (i=0; i<z; ++i)
    {
        temp = new restaurant;
        temp->ss = temp->tt = 0;
        temp->next = List[2], List[2] = temp;
    }
}// Creat_Adjacent_Table

void shiftdown(int fa, int n)
{
    int	 son;
    HEAP key=heap[fa];
    for (; fa<=n>>1; fa=son)
    {
        son = fa<<1;    /* Left_child */
        if (son!=n && heap[son+1].st<heap[son].st)
            son = son + 1;
        
        if (key.st > heap[son].st)
            heap[fa] = heap[son];
        else
            break;
    }/* End of For */
    heap[fa] = key;
}/* shiftdown */

void Insert(HEAP t)
{
    heap[++hSize] = t;
    
    int p = hSize;
    while (p!=1 && heap[p>>1].st>t.st)
    {
        heap[p] = heap[p>>1];
        p >>= 1;
    }/* End of While */
    heap[p] = t;
}// Insert

HEAP GetHeapTop()
{
    HEAP ret = heap[1];
    
    heap[1] = heap[hSize];
    heap[hSize].groups = INF;
    heap[hSize].st = heap[hSize].et = INF;
    
    --hSize;
    shiftdown( 1, hSize );
    
    return ret;
}/* PopHeadTop */

int main()
{
#if DEBUG
    freopen("E:\\hdoj_1103.txt", "r", stdin);
    freopen("E:\\hdoj_1103_ans.txt", "w", stdout);
#endif

    HEAP kk;
    restaurant *ptr, *pos;
    int a, b, c, hh, mm, ss, num;
    while ( 3==scanf("%d %d %d", &a, &b, &c), a+b+c!=0 )
    {
        //getchar();
        Creat_Adjacent_Table( a, b, c );
        
        hSize = 0;
        while ( EOF!=scanf("%s", buf), buf[0]!='#' )
        {   // !ReadLine( buf )
			scanf("%d", &num);
            sscanf( buf, "%d:%d", &hh, &mm );

            kk.st = hh*3600+mm*60, kk.et = kk.st+1800, kk.groups = num;
            Insert( kk );
        }// End of while
        
        sum = 0;
        while ( hSize )
        {
            kk = GetHeapTop();
            
            if ( kk.groups<=2 ) ptr = List[0];
            else if ( kk.groups<=4 )    ptr = List[1];
            else if ( kk.groups<=6 )    ptr = List[2];

            pos = NULL;
            int minStart = INF;
            while ( ptr!=NULL )
            {
                if ( minStart > ptr->tt )
                    minStart=ptr->tt, pos=ptr;
                
                ptr = ptr->next;
            }// Find the earliest lefing time
            
            if ( kk.et >= pos->tt )
            {
                sum += kk.groups;
                if ( pos->ss==0 && pos->tt==0 )
                    pos->ss=kk.st, pos->tt=kk.et;
                else
                    pos->ss=pos->tt, pos->tt=pos->ss+1800;
            }
        }// heap is not empty, simulation
        
        printf("%d\n", sum);
    }// End of while
    
    return 0;
}

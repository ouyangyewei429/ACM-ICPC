/*
PROG:   numtri
ID  :   ouyangyewei
LANG:   C
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define maxn 104

int N, rank[6], solved[6], result[maxn];
struct STUDENT
{
    int cnt, ti, index;
}stu[maxn];

int compare(const void *a, const void *b)
{
    STUDENT *c = (STUDENT *)a;
    STUDENT *d = (STUDENT *)b;
    
    if (c->cnt == d->cnt)
        return ( c->ti - d->ti );
    else
        return ( d->cnt - c->cnt );
}// compare

int main()
{
    int i, hh, mm, ss;
    while (~scanf("%d", &N), N!=-1)
    {
        memset(rank, 0, sizeof(rank));
        memset(solved, 0, sizeof(solved));
        for (i=0; i<N; ++i)
        {
            stu[i].index = i;
            scanf("%d", &stu[i].cnt);
            scanf("%d:%d:%d", &hh, &mm, &ss);
            stu[i].ti = hh*3600+mm*60+ss;
            
            solved[stu[i].cnt]++;
        }// Input
        
        qsort(stu, N, sizeof(stu[0]), compare);
        
        for (i=0; i<N; ++i)
        {
            switch ( stu[i].cnt )
            {
                case 5:
                    result[stu[i].index]=100;
                    break;
                case 4:
                    if ( rank[4]<solved[4]/2 )
                    {
                        ++rank[4];
                        result[stu[i].index]=95;
                    }    
                    else
                        result[stu[i].index]=90;
                    break;
                case 3:
                    if ( rank[3]<solved[3]/2 )
                    {
                        ++rank[3];
                        result[stu[i].index]=85;
                    }    
                    else
                        result[stu[i].index]=80;
                    break;
                case 2:
                    if ( rank[2]<solved[2]/2 )
                    {
                        ++rank[2];
                        result[stu[i].index]=75;
                    }    
                    else
                        result[stu[i].index]=70;
                    break;
                case 1:
                    if ( rank[1]<solved[1]/2 )
                    {
                        ++rank[1];
                        result[stu[i].index]=65;
                    }    
                    else
                        result[stu[i].index]=60;
                    break;
                case 0:
                    result[stu[i].index]=50;
                    break;
            }
        }// End of for
        
        for (i=0; i<N; ++i)
            printf("%d\n", result[i]);
        printf("\n");
    }// End of while
    
    return 0;
}

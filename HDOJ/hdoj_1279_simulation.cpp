/*
PROG:   ÑéÖ¤½Ç¹È²ÂÏë
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

const int maxn = 1004;

int N, fig, i, j, cnt, rt, oddNums, result[maxn]={0};

int main()
{
    while (~scanf("%d", &N))
    {
        for (i=0; i<N; ++i)
        {
            scanf("%d", &fig);
            for (cnt=0, oddNums=0; fig!=1; ++cnt)
            {
                result[cnt]=fig;
                if (fig & 1)
                    ++oddNums, fig=3*fig+1;
                else
                    fig>>=1;
            }// simulation
            
            if (oddNums == 0)
                printf("No number can be output !\n");
            else
            {
                for (j=0, rt=0; j<cnt; ++j)
                {
                    if (result[j]!=1 && (result[j]&1))
                    {
                        printf(rt==0 ? "%d":" %d", result[j]);
                        rt = 1;
                    }    
                }
                printf("\n");
            }// output the integer sequence
        }
    }// End of while
    
    return 0;
}

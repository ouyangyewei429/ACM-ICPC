/*
PROG:   Write a simple HTML Browser
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>

#define DEBUG 0

const int maxn = 1004;

int  lineNums=0, words=0, tlen;
char src[maxn]={0};

int main()
{
#if DEBUG
    freopen("E:\\hdoj_1088.txt", "r", stdin);
    freopen("E:\\hdoj_1088_ans.txt", "w", stdout);
#endif

    while ( gets( src ) )
    {
        char *ptr = strtok( src, " " );
        
        words = 0;
        while ( ptr!=NULL )
        {
            //printf("%s ", ptr);
            //strcat(  )
            if ( !strcmp( ptr, "<br>" ) )   // <br>
            {
				++words;
                lineNums = 0;
                printf("\n");
            }    
            else if ( !strcmp( ptr, "<hr>" ) )
            {
                if ( words )
                {
                    if ( lineNums ) printf("\n");
                    for (int i=0; i<80; ++i)
                        printf("-");
                    printf("\n");
                    
                    lineNums = 0;
                }

				++words;
            }// <hr>
            else
            {
				++words;
                tlen = strlen( ptr );
                if ( lineNums+tlen<=80 )
                {
                    printf(lineNums==0 ? "%s":" %s", ptr);
                    lineNums = ( lineNums==0 ? tlen:lineNums+1+tlen ); 
                }
                else
                {   // line Length more than 80
                    printf("\n%s", ptr);
                    lineNums = tlen;
                }
            }// words
            
            ptr = strtok( NULL, " " );
        }
    }// End of while
    printf("\n");
    
    return 0;
}// 

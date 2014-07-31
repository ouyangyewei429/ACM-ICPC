/*
PROG:   Write a simple HTML Browser
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory.h>

#define DEBUG 1

const int maxn = 10004;

int  slen;
char src[maxn]={0}, buf[256]={0};
/*
void ReadLine(char *s)
{
    char ch;
    int  k=0;
    while ( ( ch = getchar() )!=EOF )
    {
        if ( ch==' ' )  continue;
        else if ( ch=='\n' )    break;
        else    s[k++] = ch;
    }// End of for

    return ;
}// ReadLine
*/
int main()
{
#if DEBUG
    freopen("E:\\hdoj_1088.txt", "r", stdin);
    freopen("E:\\hdoj_1088_ans.txt", "w", stdout);
#endif

    slen = 0;
    while ( gets(buf) )
    {
        if ( slen!=0 )  src[slen++] = ' ';
        for (int i=0; i<strlen(buf) && buf[i]!='\n'; ++i)
        {
            src[slen++] = buf[i];
            if ( buf[i]==' ' )
            {
                while ( buf[i]==' ' )   ++i;
                --i;
            }    
        }//
    }// Merging

    for (int i=0; i<slen; ++i)
    {
        //if ( i!=0 && i%10==0 )  printf("\n");
        printf("%c", src[i]);
    }

    return 0;
}// 

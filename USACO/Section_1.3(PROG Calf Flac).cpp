/*
PROG:   calfflac
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>
#include <cctype>
//using namespace std;

#define onlinejudge

int  i, j, k, l, r, slen, cnt, maxlen, cr[20004];
char ch, tmp[20004], line[20004];
struct pal
{
	char c;
	int  index;
}bunch[20004];

int main()
{
/*
#ifdef onlinejudge
    freopen("E:\\cal.txt", "r", stdin);
    freopen("E:\\cal_ans.txt", "w", stdout);
#endif
*/
    freopen("calfflac.in", "r", stdin);
    freopen("calfflac.out", "w", stdout);

    memset(line, 0, sizeof(line));
    memset(bunch, 0, sizeof(bunch));
    while (gets(tmp) != NULL)
        strcat(line, tmp), cr[strlen(line)-1]=1;
    
    for (i=0,slen=0; i<strlen(line); ++i)
    {
        if (isalpha(line[i]))
            bunch[slen].c=tolower(line[i]), bunch[slen].index=i, slen++;
    }/* reserve letter */
    bunch[slen].c = '\0';
    
    /*
    for (i=0; i<slen; ++i)
        printf("%c", bunch[i]);
    printf("\n");
    */
    
    for (maxlen=-1, i=1; i<slen; ++i)
    {
        j=0, cnt=0;
        while (i-j>=0 && i+j+1<slen && bunch[i-j].c==bunch[i+j+1].c)
            ++j, ++cnt;
        
		cnt--;
        if (2*cnt+2 > maxlen)
            maxlen=(2*cnt+2), l=bunch[i-cnt].index, r=bunch[i+cnt+1].index;
        
        j=0, cnt=0;
        while (i-j>=0 && i+j<slen && bunch[i-j].c==bunch[i+j].c)
            ++j, ++cnt;
        
		cnt--;
        if (2*cnt+1 > maxlen)
            maxlen=2*cnt+1, l=bunch[i-cnt].index, r=bunch[i+cnt].index;
    }/* Find the longest palindromes */

    printf("%d\n", maxlen);
    for (k=l; k<=r; ++k)
    {
		printf("%c", line[k]);
        if (cr[k] == 1) printf("\n");
    }    	
    if (cr[r]!=1)   printf("\n");

    return 0;
}

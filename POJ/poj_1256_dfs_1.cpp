/*
PROG:   Anagram
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

bool hash[15];
int  T, slen;
char temp, ss[15], words[15];

inline int compare(char a, char b)
{
    double c = a;
    double d = b;
    
    if (a>='A' && a<='Z')   c += 31.5;
    if (d>='A' && d<='Z')   d += 31.5;
    return (int)(c<d);
}/* compare */

void dfs(int cnt)
{
    if (cnt == slen)
    {
        ss[cnt] = '\0';
        printf("%s\n", ss);
        return ;
    }/* destination */
    
    for (int i=0; i<slen; ++i)
    {
        if (hash[i])
            continue;
    
        hash[i]=true, ss[cnt]=words[i];
        dfs(cnt+1);
        hash[i]=false;

		while (i+1<slen && words[i]==words[i+1]) ++i;
    }/* End of For */
}/* dfs */

int main()
{
    scanf("%d", &T);
    getchar();
    while (T--)
    {
        //cin >> words;
        scanf("%s", words);
        
        slen = strlen(words);
        sort(words, words+slen, compare);

        memset(hash, false, sizeof(hash));
        dfs(0);
		//printf("%s\n", words);
    }/* End of While */

    return 0;
}

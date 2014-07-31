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
using namespace std;

bool hash[15];
int  T, slen;
char temp, ss[15], words[15];

void ss_sort()
{
	for (int i=0; i<slen-1; ++i)
    {
        int k=i;
        for (int j=i+1; j<slen; ++j)
        {
            if (islower(words[k]) && islower(words[j]) && words[k]>words[j])
                k = j;
            else if (isupper(words[k]) && isupper(words[j]) && words[k]>words[j])
                k = j;
            else if (isupper(words[k]) && islower(words[j]) && tolower(words[k])>words[j])
                k = j;
            else if (islower(words[k]) && isupper(words[j])
                    && (words[k]>tolower(words[j]) || words[k]==tolower(words[j])))
                k = j;
        }
        if (k != i)
            temp=words[k], words[k]=words[i], words[i]=temp;
    }/* sort */
}

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
    while (T--)
    {
        cin >> words;
        
        slen = strlen(words);
        ss_sort();

        memset(hash, false, sizeof(hash));
        dfs(0);
		//printf("%s\n", words);
    }/* End of While */

    return 0;
}

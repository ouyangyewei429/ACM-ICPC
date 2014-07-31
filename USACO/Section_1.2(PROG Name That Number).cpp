/*
PROG:   namenum
ID  :   ouyangyewei
LANG:   C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

const int maxn = 15;

bool IsSolved;
int  nwords;
char name[maxn], num[maxn], dict[5004][maxn];
char mirror[][3] = {{'A','B','C'}, {'D','E','F'}, {'G','H','I'}, 
                 {'J','K','L'}, {'M','N','O'}, {'P','R','S'},
                 {'T','U','V'}, {'W','X','Y'}};

void Bin_Search()
{
    int left=1, right=nwords, mid;
    
    while (left <= right)
    {
        mid = (left+right)>>1;
        if (strcmp(name, dict[mid]) == 0)
        {
            IsSolved = true;
            printf("%s\n", name);
            return ;
        }
        else if (strcmp(name, dict[mid]) < 0)
            right = mid-1;
        else
            left = mid+1;
    }/* End of While */
}/* Bin_Search */

void CowName(int cnt, int N)
{
    if (cnt == N)
    {
        name[cnt] = '\0';
        Bin_Search();
        return ;
    }/* End of If */
    
    for (int i=0; i<3; ++i)
    {
        name[cnt] = mirror[num[cnt]-'2'][i];
        CowName(cnt+1, N);
    }/* End of For */
}/* CowName */
                 
int main()
{
    FILE *fin = fopen("dict.txt", "r");
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);

    /* Access to the Valid Name */
    for (nwords=1; fscanf(fin, "%s", &dict[nwords])!=EOF; ++nwords);
    //fin.close();
    
    while (~scanf("%s", num))
    {
        IsSolved = false;
        int len = strlen(num);
        CowName(0, len);
        
        if (!IsSolved)
            printf("NONE\n");
    }/* End of While */
        
    return 0;
}

/*
PROG:   Train Problem I
ID  :   ouyangyewei
LANG:   C++
*/
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory.h>
using namespace std;

const int maxn = 12;

int  N, i, j, k;
char first[maxn], second[maxn], ans[maxn<<2][maxn]={0};

int main()
{
    while (cin >> N >> first >> second)
    {
        stack <char> st;
        memset(ans, 0, sizeof(ans));
        
        for (i=0, j=0, k=0; i<strlen(first)+1&&j<strlen(second); )
        {
            if (st.empty())
                st.push(first[i++]), memcpy(ans[k++], "in", 3);
            else if (st.top() == second[j])
                ++j, memcpy(ans[k++], "out", 4), st.pop();
            else
                st.push(first[i++]), memcpy(ans[k++], "in", 3);
        }/* End of For */
        
        if (!st.empty())
        {
            printf("No.\nFINISH\n");
            continue;
        }
        else
        {
            printf("Yes.\n");
            for (i=0; i<k; ++i)
                printf("%s\n", ans[i]);
            printf("FINISH\n");
        }
    }/* End of While */
    
    return 0;
}

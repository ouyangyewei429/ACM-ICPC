/*
PROG:   Anagrams by Stack
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

#define onlinejudge

const int maxn = 1010;

stack <char> st;
char words[maxn], goal[maxn], ss[maxn], path[maxn<<1];

void dfs(int cnt, int steps, int len)
{
    if (steps == 2*len)
    {
        if (memcmp(ss, goal, len) == 0)
        {
            int i=0;
            while (!ans.empty())
            {
                ans
            }
            steps = 0;
            for ()
                printf(i==0 ? "%c":" %c", path[i]);
            printf("\n");
        }
        
        return ;
    }/* destination */
    
    for (int i=0; i<len; ++i)
    {
        st.push(words[i]);
        path[steps] = 'i';
        dfs(cnt, steps+1, len);
        
        if (!st.empty())
        {
            ss[cnt] = st.top();
            st.pop();
            path[steps] = 'o';
            dfs(cnt+1, steps+1, len);
        }// pop a elem    
    }/* End of For */
}/* dfs */

int main()
{
#ifdef onlinejudge
    freopen("E:\\zoj_1004.txt", "r", stdin);
    freopen("E:\\zoj_1004_ans.txt", "w", stdout);
#endif

    while (cin >> words >> goal)
    {
        while (!st.empty()) st.pop();
        memset(path, 0, sizeof(sizeof(path)));
        
        printf("[\n");
        dfs(0, 0, strlen(words));
        printf("]\n");
    }/* End of While */
    
    return 0;
}

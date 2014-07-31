/*
PROG:
ID  :   ouyangyewei
LANG:   C++
*/
//#pragma warnning (disable : 4786)

#include <set>
#include <map>
#include <cmath>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define DEBUG 0

bool vis[12];

void dfs(int &N, int &M, int depth, string ss) {
    if (depth == M) {
        cout << ss << endl;
        return ;
    } else {
        for (int ix = 1; ix <= N; ++ix) {
            if (!vis[ix]) {
                vis[ix] = true;
                dfs(N, M, depth + 1, ss + (char)(ix + '0'));
                vis[ix] = false;
            }
        }// End of for
    }
}

int main() 
{
#if DEBUG
    freopen("E:\\", "r" ,stdin);
    freopen("E:\\", "w", stdout);
#endif

    string ss;
    int testCases, N, M;
    
    scanf("%d", &testCases);
    while (testCases--) {
        scanf("%d %d", &N, &M);
        
        ss = "";
        memset(vis, false, sizeof(vis));
        dfs(N, M, 0, ss);
    }// End of while
    return 0;
}
/*
运行号		用户 	题目 	结果 	时间 	内存 	语言 	提交时间
247244 	FLex	擅长排列的小明	Accepted 	72 	308 	C/C++	09-20 16:41:46
*/

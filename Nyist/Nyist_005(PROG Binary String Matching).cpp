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

void solve(string &T, string &S, int &appearTimes) {
    string::size_type found;
    
    appearTimes = 0;
    while (S != "") {
        found = S.find(T);
        if (found != string::npos)
            ++appearTimes;
        else
            break;
        S = S.substr(found + 1);
    }
    return ;
}

int main() 
{
#if DEBUG
    freopen("E:\\nyist_005.in", "r" ,stdin);
    freopen("E:\\nyist_005.out", "w", stdout);
#endif
    
    int testCases, appearTimes;
    string S, T;
    
    scanf("%d", &testCases);
    while (testCases--) {
        cin >> T >> S;
        solve(T, S, appearTimes);
        printf("%d\n", appearTimes);
    }// End of while
    return 0;
}
/*
运行号		用户 	题目 	结果 	时间 	内存 	语言 	提交时间
247219 	FLex	Binary String Matching	Accepted 	0 	308 	C/C++	09-20 15:38:37
*/

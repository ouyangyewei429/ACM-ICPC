/*
PROG:   Same binary weight
ID  :   ouyangyewei
LANG:   C++
*/
//#pragma warnning (disable : 4530)
//#pragma warnning (disable : 4786)

#include <set>
#include <map>
#include <stack>
#include <queue>
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

typedef long long LL;

int main() 
{
    LL x, b, t, s, k;
    
    while (~scanf("%lld", &x)) {
        b = x & (-x);
        t = x + b;
        s = t ^ x;
        k = (s >> 2) / b;
        printf("%lld\n", t | k);
    }// End of while
    return 0;
}
/*
运行号		用户 	题目 	结果 	时间 	内存 	语言 	提交时间
247564 	FLex	Same binary weight	Accepted 	0 	228 	C/C++	09-21 10:36:21
*/

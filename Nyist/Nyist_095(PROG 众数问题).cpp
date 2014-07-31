/*
PROG:   众数问题
ID  :   ouyangyewei
LANG:   C++
*/
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

typedef multiset<int> MSI;
typedef multiset<int>::iterator MSIT;

int main() 
{
    MSI sc;
    MSI::size_type cNums, mNums;
    MSIT iter;
    int testCases, nNums, xx, mode;
    
    scanf("%d", &testCases);
    while (testCases--) {
        sc.clear();
        scanf("%d", &nNums);
        for (int i = 0; i < nNums; ++i) {
            scanf("%d", &xx);
            sc.insert( xx );
        }
        
        mNums = 0;
        for (iter = sc.begin(); iter != sc.end(); ++iter) {
            cNums = sc.count(*iter);
            if ( mNums < cNums ) {
                mNums = cNums;
                mode = *iter;
            }
        }
        printf("%d %d\n", mode, mNums);
    }// End of while
    return 0;
}
/*
运行号		用户 	题目 	结果 	时间 	内存 	语言 	提交时间
247323 	FLex	众数问题	Accepted 	0 	308 	C/C++	09-20 19:44:09
*/

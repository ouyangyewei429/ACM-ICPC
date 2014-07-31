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

struct Rectangle {
    int number, length, width;
};
typedef Rectangle Rect;

struct compare {
    bool operator ()(Rect c, Rect d) const {
        if (c.number == d.number) {
            if (c.length == d.length)
                return c.width < d.width;
            else
                return c.length < d.length;
        } else {
            return c.number < d.number;
        }
    }    
};
typedef set<Rect, compare> SRC;

int main() 
{
#if DEBUG
    freopen("E:\\nyist_008.in", "r" ,stdin);
    freopen("E:\\nyist_008.out", "w", stdout);
#endif

    SRC sc;
    Rect rt;
    int testCases, nNums;
    
    scanf("%d", &testCases);
    while (testCases--) {
        sc.clear();
        scanf("%d", &nNums);
        for (int i = 0; i < nNums; ++i) {
            scanf("%d %d %d", &rt.number, &rt.length, &rt.width);
            if (rt.length < rt.width)
                swap(rt.length, rt.width);
            sc.insert(rt);
        }
        
        SRC::iterator iter;
        for (iter = sc.begin(); iter != sc.end(); ++iter)
            printf("%d %d %d\n", iter -> number, iter -> length, iter -> width);
    }// End of while
    return 0;
}
/*
运行号		用户 	题目 	结果 	时间 	内存 	语言 	提交时间
247235 	FLex	一种排序	Accepted 	4 	308 	C/C++	09-20 16:24:12
*/

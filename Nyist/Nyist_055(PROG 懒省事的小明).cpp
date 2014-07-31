/*
PROG:
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

typedef long long LL;

struct compare {
    bool operator ()(const LL &c, const LL &d) const {
        return c > d;
    }
};

int main() 
{
    LL p1, p2, sum;
    int testCases, nNums, pile;
    priority_queue<LL, vector<LL>, compare> pq;
    
    scanf("%d", &testCases);
    while (testCases--) {
        while (!pq.empty())
            pq.pop();
            
        scanf("%d", &nNums);
        for (int i = 0; i < nNums; ++i) {
            scanf("%d", &pile);
            pq.push(pile);
        }
        if (pq.size() == 1) {
            sum = pq.top();
        } else {
            sum = 0;
            while (pq.size() > 1) {
                p1 = pq.top();
                pq.pop();
                p2 = pq.top();
                pq.pop();
                sum += p1 + p2;
                pq.push(p1 + p2);
            }// End of while
        }
        printf("%lld\n", sum);
    }// End of while
    return 0;
}
/*
运行号		用户 	题目 	结果 	时间 	内存 	语言 	提交时间
247285 	FLex	懒省事的小明	Accepted 	144 	440 	C/C++	09-20 18:18:10
*/

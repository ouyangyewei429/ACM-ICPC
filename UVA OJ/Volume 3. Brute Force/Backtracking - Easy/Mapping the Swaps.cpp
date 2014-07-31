/*
PROG:   Mapping the Swaps
ID  :   ouyangyewei
LANG:   C++
*/
#pragma warnning (disable : 4786)

#include <set>
#include <map>
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

int N, maps, cas = 1, a[200] = {0};

bool isOrder() {
    for (int i = 0; i < N - 1; ++i) {
      if (a[i] > a[i + 1])
        return false;
    }
    return true;
}

void dfs() {
    if ( isOrder() ) {
      ++maps;
      return ;
    }
    
    int tmp;
    for (int i = 0; i < N - 1; ++i) {
      if ( a[i] > a[i + 1] ) {
        tmp = a[i], a[i] = a[i + 1], a[i + 1] = tmp;
        dfs();
        tmp = a[i], a[i] = a[i + 1], a[i + 1] = tmp;
      }
    }// End of for
}

int main() {
#if DEBUG
    freopen("E:\\331.in", "r" ,stdin);
    freopen("E:\\331.out", "w", stdout);
#endif

    while (~scanf("%d", &N) && N) {
      for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
      }
      if (isOrder()) {
        printf("There are 0 swap maps for input data set %d.\n", cas++);
      } else {
        maps = 0;
        dfs();
        printf("There are %d swap maps for input data set %d.\n", maps, cas++);
      }
    }// End of while

    return 0;
}
/*
# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
10600754 	331 	Mapping the Swaps 	Accepted 	C++ 	0.016 	2012-09-14 07:20:44
*/

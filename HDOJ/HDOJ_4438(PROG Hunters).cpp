/*
PROG:   Hunters
ID  :   ouyangyewei
LANG:   C++
*/
//#pragma warnning (diaable : 4530)
//#pragma warnning (disable : 4786)

#include <set>
#include <map>
#include <list>
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
#include <fstream>
#include <algorithm>

using namespace std;

int T;
__int64 x, y;
double p, q, tiger, wolf;

int main() 
{
    scanf("%d", &T);
    while (T--) {
        scanf("%I64d %I64d %lf %lf", &x, &y, &p, &q);
        tiger = (1 - q) * x + p * q * (x + y);
        wolf = q * y + (1 - q) * p * (x + y);
        if (tiger > wolf)
            printf("tiger %.4lf\n", tiger);
        else
            printf("wolf %.4lf\n", wolf);
    }// End of while
    return 0;
}

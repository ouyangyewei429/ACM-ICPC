/*
PROG:
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

#define DEBUG 0

const int MAXN = 100;

struct Matrix {
    int row, col;
}mat[MAXN];

char mx;
string line;
int nMats, r, c, an, bn;
stack<int> s;

void readData() {
    scanf("%d", &nMats);
    for (int i = 0; i < nMats; ++i) {
		getchar();
        scanf("%c %d %d", &mx, &r, &c);
        mat[mx - 'A'].row = r, mat[mx - 'A'].col = c;
    }// End of for
}

long process() {
    long sum = 0;
    string::size_type ix;
    string::size_type slen = line.length();
    
    for (ix = 0; ix < slen; ++ix) {
        if (line[ix] == '(') {
            s.push(-1);
        } else if (isupper(line[ix])) {
            s.push(line[ix] - 'A');
        } else if (line[ix] == ')') {
            bn = s.top(), s.pop();
            an = s.top(), s.pop();
            s.pop();  // pop '('
            if (mat[an].col != mat[bn].row) {
                return -1;
            } else {
                sum += (mat[an].row * mat[an].col * mat[bn].col);
                mat[nMats].row = mat[an].row, mat[nMats].col = mat[bn].col;
                s.push(nMats++);
            }
        }
    }// End of for
    if (s.size() > 1) {
        bn = s.top(), s.pop();
        an = s.top(), s.pop();
        sum += (mat[an].row * mat[an].col * mat[bn].col);
    }
    return sum;
}

void Initialize(long &ans) {
    ans = 0;
    while (!s.empty())
        s.pop();
}

void solve() {
    long ans = 0;
    while (cin >> line) {
        ans = process();
        if (ans == -1)
            printf("error\n");
        else
            printf("%d\n", ans);
        Initialize(ans);
    }// End of while
}

int main() 
{
#if DEBUG
    freopen("E:\\442.in", "r" ,stdin);
    freopen("E:\\442.out", "w", stdout);
#endif

    readData();
    solve();
    return 0;
}
/*
# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
10711296 	442 	Matrix Chain Multiplication 	Accepted 	C++ 	0.008 	2012-10-10 09:11:13
*/

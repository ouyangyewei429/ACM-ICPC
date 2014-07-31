/*
PROG:   Kindergarten Counting Game
ID  :   ouyangyewei
LANG:   C++
*/
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

#define DEBUG 0

namespace {

char line[1004];

inline void Trans() {
    for (int i = 0; i < strlen(line); ++i) {
        if (!isalpha(line[i])) {
            line[i] = ' ';
        }
    }
}// Trans

inline void Solve() {
    int wordnums = 0;
    char *delim = strtok(line, " ");  // get the first word
    while (delim != NULL) {  // seperate words
        ++wordnums;
        delim = strtok(NULL, " ");
    }
    
    printf("%d\n", wordnums);
}// Solve

}// namespace

int main() {
#if DEBUG
    freopen("E:\\494.in", "r", stdin);
    freopen("E:\\494.out", "w", stdout);
#endif

    while (gets(line)) {
        Trans();
        Solve();
        memset(line, 0, sizeof(line));
    }// End of while

    return 0;
}
/*
# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
10531987 	494 	Kindergarten Counting Game 	Accepted 	C++ 	0.008 	2012-08-28 02:40:46
*/

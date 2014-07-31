/*
PROG:   Marvelous Mazes
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <iostream>

using namespace std;

#define DEBUG 0

int main() {
#if DEBUG
    freopen("E:\\445.in", "r", stdin);
    freopen("E:\\455.out", "w", stdout);
#endif

    char c;
    int cnt = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == '!') {
            printf("\n");
        } else if (isdigit(c)) {  // isdigit
            cnt += (c - '0');
        } else if (isalpha(c) || c == '*') {  // isalpha
            for (int i = 0; i < cnt; ++i) {  // print the letter
                printf(c == 'b' ? " ":"%c", c);
            }
            
            cnt = 0;  // reset the count
        }
    }// End of while

    return 0;
}
/*
# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
10533639 	445 	Marvelous Mazes 	Accepted 	C++ 	0.008 	2012-08-28 12:45:42
*/

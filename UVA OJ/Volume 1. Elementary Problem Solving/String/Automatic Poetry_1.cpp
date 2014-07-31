/*
PROG:   Automatic Poetry
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

#define DEBUG 0

void DisFirString(string &first) {
    int firLen = first.length();
    
    for (int i = 0; i < firLen; ++i) {
        if (first[i] != '<' && first[i] != '>') {
            cout << first[i];
        }
    }
    cout << endl;
}

void DisSecString(string &first, string &second) {
    int i, j, pos[5];
    int firLen = first.length();
    int secLen = second.length();
    string s2, s3, s4, s5;
    
    // Get the '<' and '>' position
    for (i = 0, j = 1; i < firLen; ++i) {
        if (first[i] == '<' || first[i] == '>') {
            pos[j++] = i;
        }
    }
    
    // Get <s2>
    for (i = pos[1] + 1; i < pos[2]; ++i) {
        s2 += first[i];
    }
    // Get <s2>s3
    for (i = pos[2] + 1; i < pos[3]; ++i) {
        s3 += first[i];
    }
    // Get <s2>s3<s4>
    for (i = pos[3] + 1; i < pos[4]; ++i) {
        s4 += first[i];
    }
    // Get <s2>s3<s4>s5
    for (i = pos[4] + 1; i < firLen; ++i) {
        s5 += first[i];
    }
    
    // display string 'second'
    for (i = 0; i < secLen; ++i) {
        if (second[i] != '.') {
            cout << second[i];
        } else {
            cout << s4 << s3 << s2 << s5 << endl;
            break;
        }
    }
}

int main() {
#if DEBUG
    freopen("E:\\10361.in", "r", stdin);
    freopen("E:\\10361.out", "w", stdout);
#endif

    int testCases;
    string first, second, s2, s3, s4, s5;
    
    cin >> testCases;
    getchar();  // get the carry return
    while (testCases--) {
        getline(cin, first);
        getline(cin, second);
        
        DisFirString(first);
        DisSecString(first, second);
    }// End of while

    return 0;
}
/*
# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
10574460 	10361 	Automatic Poetry 	Accepted 	C++ 	0.008 	2012-09-07 10:42:14
*/

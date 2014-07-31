/*
PROG:   Automatic Poetry
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define DEBUG 0

// 對於 string 'second'，去掉 "..." 並且加上 s4s3s2s5 
void func_2(string &first, string &second) {
    string s2, s3, s4, s5, tmp;
    string::size_type i, firLen = first.length();
    string::size_type pos = first.find("<");
    
    for (++pos; first[pos] != '>' && pos < firLen; ++pos) {  // s2
        s2 += first[pos];
    }
    for (++pos; first[pos] != ' ' && pos < firLen; ++pos) {  // s3
        s3 += first[pos];
    }
    for (pos += 2; first[pos] != '>' && pos < firLen; ++pos) {  // s4
        s4 += first[pos];
    }
    for (++pos; first[pos] != ' ' && pos < firLen; ++pos) {  // s5
        s5 += first[pos];
    }
    
    tmp = s4 + s3 + " " + s2 + s5;
    pos = second.find("...");
    second.replace(pos, 3, tmp);
}

// 對於 string 'first'，去掉 "<" 和 ">"
void func_1(string &first) {
    int firLen = first.length();
    string str;
    
    for (int i = 0; i < firLen; ++i) {
        if (first[i] != '>' && first[i] != '<') {
            str += first[i];
        }
    }
    first = str;
}

int main() {
#if DEBUG
    freopen("E:\\10361.in", "r", stdin);
    freopen("E:\\10361.out", "w", stdout);
#endif

    int testCases;
    string first, second;
    
    cin >> testCases;
    getchar();
    while (testCases--) {
        getline(cin, first);
        getline(cin, second);
        
        func_2(first, second);
        func_1(first);
        cout << first << endl << second << endl;
    }// End of while

    return 0;
}

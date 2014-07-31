/*
PROG:   Andy's First Dictionary
ID  :   ouyangyewei
LANG:   C++
*/
#include <set>
#include <vector>
#include <string>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

typedef set<string> SCP;

#define DEBUG 0

int main() {
#if DEBUG
    freopen("E:\\10815.in", "r", stdin);
    freopen("E:\\10815.out", "w", stdout);
#endif

    char ch;
    string ss;
    while ((ch = getchar()) != EOF) {
        ss += tolower(ch);
    }// End of while
    
    SCP dict;  // µ¥´Ê¼¯ºÏ
    string tt;
    string::size_type slen = ss.length();
    for (int i = 0; i < slen; ++i) {
        if (isalpha(ss[i])) {
            tt += ss[i];
        } else if (tt != "") {
            dict.insert(tt);
            tt = "";
        }
    }
    
    SCP::iterator iter;
    for (iter = dict.begin(); iter != dict.end(); ++iter) {
        cout << *iter << endl;
    }

    return 0;
}

/*
PROG:   Automatic Editing
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <utility>
#include <iostream>

using namespace std;

typedef pair<string, string> PSS;
typedef vector<PSS> VSS;

#define DEBUG 0

// Data Input
void ReadData(VSS &data, string &text, int &testCases) {
    string first, second;
    
    for (int i = 0; i < testCases; ++i) {
        getline(cin, first);
        getline(cin, second);
        data.push_back(make_pair(first, second));
    }
    getline(cin, text);
}

// 将 text 中所有 src 字符串全部替换成 dst
void StringReplace(const string &src, const string &dst, string &text) {
    string::size_type srcLen = src.size();
    string::size_type dstLen = dst.size();
    string::size_type pos = text.find(src);
    
    while (pos != string::npos) {
        text.replace(pos, srcLen, dst);
        pos = text.find(src);
    }
}

// 将文本中所有 frist 字符串全部替换成 second
void ReplaceText(const VSS &data, string &text) {
    int vSize = data.size();
    
    for (int i = 0; i < vSize; ++i) {
        StringReplace(data[i].first, data[i].second, text);
    }
} 

int main() {
#if DEBUG
    freopen("E:\\10115.in", "r", stdin);
    freopen("E:\\10115.out", "w", stdout);
#endif

    VSS data;
    string text;
    int testCases;
    
    while (cin >> testCases && testCases) {
		getchar();
		data.clear();
        ReadData(data, text, testCases);
        ReplaceText(data, text);
        cout << text << endl;
    }// End of while

    return 0;
}

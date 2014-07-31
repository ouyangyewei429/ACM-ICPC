/*
PROG:   Intelligent IME
ID  :   ouyangyewei
LANG:   C++
*/
#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

#define DEBUG 0

const string ss = "22233344455566677778889999";

void Cal(string &nums, string &str) {
    int slen = str.length();
    
    nums = "";
    for (int i = 0; i < slen; ++i) {
        nums += ss[str[i]-'a'];
    }
}

int main() {
#if DEBUG
    freopen("E:\\4287.in", "r", stdin);
    freopen("E:\\4287.out", "w", stdout);
#endif

    int T, N, M, i, j;
    
    scanf("%d", &T);
    for (i = 1; i <= T; ++i) {
        scanf("%d %d", &N, &M);
        
        string str, nums;
        vector<string> v;
        map<string, int> mp;
        
        for (j = 0; j < N; ++j) {
            cin >> str;
            v.push_back(str);
            mp[str] = 0;
        }
        for (j = 0; j < M; ++j) {
            cin >> str;
            Cal(nums, str);
            ++mp[nums];
        }
        
        for (j = 0; j < N; ++j) {
            if (mp[v[j]] == 0) {
                //cout << "0" << endl;
                printf("0\n");
            } else {
                //cout << mp[v[j]] << endl;
                printf("%d\n", mp[v[j]]);
            }
        }
    }// End of for

    return 0;
}

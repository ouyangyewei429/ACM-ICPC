/*
PROG:   Immediate Decodability
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define DEBUG 0

struct TrieNode {
    bool isEnd;
    TrieNode *branch[2];
    TrieNode() {
        isEnd = false;
        branch[0] = branch[1] = NULL;
    }
};

class Trie {
    private:
        TrieNode *root_;
    
    public:
        Trie();
        bool TrieInsert(const string &);
};

// Init
Trie::Trie() {
    root_ = new TrieNode();
}

// 將 string 'ss' 插入到字典樹中
// 插入成功返回 true，否則返回 false 
bool Trie::TrieInsert(const string &ss) {
    TrieNode *ptr = root_;
    int slen = ss.length();
    
    for (int i = 0; i < slen; ++i) {
        if (i == slen - 1 && ptr -> branch[ss[i] - '0']) {
            return false;
        } else if (ptr -> branch[ss[i] - '0'] == NULL) {
            TrieNode *tempPtr = new TrieNode();
            ptr -> branch[ss[i] - '0'] = tempPtr;
        } else if (ptr -> branch[ss[i] - '0'] -> isEnd) {
            return false;
        }
        
        ptr = ptr -> branch[ss[i] - '0'];
    }
    
    ptr -> isEnd = true;
    return true;
}

// 建立字典樹對問題進行求解，若是出現前綴單詞則返回 true 
bool IsPrefix(const vector<string> &data) {
    Trie t;  // creat a trie tree
    int N = data.size();
    bool flag = false;
    
    // 將string插入到字典樹 t 中，
    // 插入成功說明暫時沒有出現前綴單詞，不成功說明已經出現前綴單詞 
    for (int i = 0; i < N; ++i) {
        if (t.TrieInsert(data[i]) == false) {  // 出現前綴單詞，插入不成功 
            flag = true;
        }
    }
    
    return flag;
}

int main() {
#if DEBUG
    freopen("E:\\644.in", "r", stdin);
    freopen("E:\\644.out", "w", stdout);
#endif

    string codes;
    vector<string> data;
    int cnt = 0, setNums = 1;
    
    while (cin >> codes) {
        if (codes == "9") {
            if (IsPrefix(data)) {
                printf("Set %d is not immediately decodable\n", setNums++);
            } else {
                printf("Set %d is immediately decodable\n", setNums++);
            }
            
            data.clear();
        } else {
            data.push_back(codes);
        }
    }// End of while

    return 0;
}

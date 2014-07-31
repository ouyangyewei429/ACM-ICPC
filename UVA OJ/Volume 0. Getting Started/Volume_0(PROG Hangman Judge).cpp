/*
PROG:   Hangman Judge
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

#define DEBUG 0

class Hangman {
    private:
        string hang_, guess_;
        bool hash_[27];
        
    public:
        Hangman(string &, string &);
        string dupRemoval(string);
        void simula(int &);
};

// remove the repetitive character
string Hangman::dupRemoval(string ss) {
    string ret = "";
    int slen = ss.length();
    
    for (int i = 0; i < slen ; ++i) {
        for (int j = i+1; j < slen; ++j) {
            if (ss[j] == ss[i]) {
                ss[j] = ' ';
            }
        }
        if (ss[i] != ' ') {
            ret += ss[i];
        }
    }
    
    return ret;
}

// Init
Hangman::Hangman(string &first, string &second) {
    hang_ = dupRemoval(first);
    guess_ = dupRemoval(second);

	int slen = hang_.length();

	memset(hash_, false, sizeof(hash_));
	for (int i = 0; i < slen; ++i) {
		hash_[hang_[i]-'a'] = true;
	}
}

// 1. 若比较 7 次或以上仍无法将 first 比较完，为 lost
// 2. 若在 7 次内将 first 比较完，为 win
// 3. 若在 7 次内，未将 first 比较完，second 就遍历结束了，为 chickened out
void Hangman::simula(int &rounds) {
    int k, strokes = 0;
    int slen = guess_.length();
    int tot = hang_.length();
    
    for (k = 0; k < slen ; ++k) {
        // second[k] is exist in string 'first'
        if (hash_[guess_[k]-'a'] == true) {
            --tot;
        } else {  // second[k] isn't exist in string 'first'
            ++strokes;
            if (strokes >= 7) break;
        }
    }
    
    cout << "Round " << rounds << endl;
    if (strokes >= 7) {
        cout << "You lose." << endl;
    } else if (strokes < 7 && tot == 0) {
        cout << "You win." << endl;
    } else if (strokes < 7 && k >= slen) {
        cout << "You chickened out." << endl;
    }
}

int main() {
#if DEBUG
    freopen("E:\\489.in", "r", stdin);
    freopen("E:\\489.out", "w", stdout);
#endif

    int rounds;
    string first, second;
    
    while (cin >> rounds && rounds != -1) {        
        cin >> first >> second;
        
        Hangman obj(first, second);  // define an object
        obj.simula(rounds);
    }// End of while

    return 0;
}

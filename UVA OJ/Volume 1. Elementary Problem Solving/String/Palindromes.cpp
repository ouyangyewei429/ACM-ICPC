/*
PROG:   Palindromes
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

#define DEBUG 0

const char NUMRIC[] = " 1SE    8 ";
const char ALPHA[] = "A   3  HIL JM O   2TUVWXY5";

class Palindromes {
    private:
        string ss_;

    public:
        Palindromes(string);
        bool isPalindromes();
        bool isMirror();
};

// Init
Palindromes::Palindromes(string tt) {
    ss_ = tt;
}

// check string 'tt' if is a palindrome
bool Palindromes::isPalindromes() {
    int slen = ss_.length();
    for (int i = 0; i <= (slen>>1); ++i) {
        if ((ss_[i] == '0' && ss_[slen-i-1] == 'O')
            || (ss_[i] == 'O' && ss_[slen-i-1] == '0')) {
            continue;
        } else if (ss_[i] != ss_[slen-i-1]) {
            return false;
        }
    }
    
    return true;
}

// check string 'tt' if is a mirror
bool Palindromes::isMirror() {
    string reverse = "";
    int slen = ss_.length();
    
    for (int i = slen - 1; i >= 0; --i) {
        if (isdigit(ss_[i])) {
            if (NUMRIC[ss_[i] - '0'] != ' ') {
                reverse += NUMRIC[ss_[i] - '0'];
            }
        } else if (ALPHA[ss_[i] - 'A'] != ' ') {
            reverse += ALPHA[ss_[i] - 'A'];
        }
    }

    return reverse == ss_;
}

int main() {
#if DEBUG
    freopen("E:\\401.in", "r", stdin);
    freopen("E:\\401.out", "w", stdout);
#endif

    string inString;
    
    while (cin >> inString) {
        Palindromes obj(inString);
        bool palind = obj.isPalindromes();
        bool mirror = obj.isMirror();
        
        if (!palind && !mirror) {
            cout << inString << " -- is not a palindrome." << endl;
        } else if (palind && !mirror) {
            cout << inString << " -- is a regular palindrome." << endl;
        } else if (!palind && mirror) {
            cout << inString << " -- is a mirrored string." << endl;
        } else if (palind && mirror) {
            cout << inString << " -- is a mirrored palindrome." << endl;
        }
        
        cout << endl;
    }// End of while

    return 0;
}

/*
PROG:   ×Ö·û´®Ìæ»»
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

class Transform {
    private:
        string ss_;
    
    public:
        Transform(string);
        void changeWords();
};

// Init
Transform::Transform(string tt) {
    ss_ = tt;
}

// change 'you' into 'we'
void Transform::changeWords() {
    int found = ss_.find("you");
    
    while (found != string::npos) {
        ss_.replace(found, 3, "we");
        found = ss_.find("you", found+1, 3);
    }
    cout << ss_ << endl;
}

int main() {
    string inString;
    
    while (getline(cin, inString)) {
        Transform obj(inString);
        
        obj.changeWords();
    }// End of while

    return 0;
}
/*
Sample Input:
    you are what you do

Sample Output:
    we are what we do
*/

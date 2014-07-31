/*
PROG:   Generating Fast, Sorted Permutation
ID  :   ouyangyewei
LANG:   C++
*/
#include <memory.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

#define DEBUG 0

namespace {

int testCases;
string bunch;
bool hash[12];

// Given a string
// Dfs(int, string) will generate its permutation
//
void Dfs(int length, int count, string ss, string tt) {
  if (count == length) {  // generate a new bunch
    cout << ss << endl;
    return ;
  }

  for (int i = 0; i < length; ++i) {
    if (!i || tt[i] != tt[i-1]) {
      int c1 = 0, c2 = 0;
      for (int j = 0; j < count; ++j) if (ss[j] == tt[i]) ++c1;
      for (int j = 0; j < length; ++j) if (tt[j] == tt[i]) ++c2;
      if (c1 < c2) {
        Dfs(length, count+1, ss+tt[i], tt);
      }
    }
  }
}// Dfs

}// namespace

int main() {
#if DEBUG
  freopen("E:\\10098.in", "r", stdin);
  freopen("E:\\10098.out", "w", stdout);
#endif

  while (cin >> testCases) {
    for (int k = 0; k < testCases; ++k) {
      cin >> bunch;
      sort(bunch.begin(), bunch.end());  // sorting bunch in ascending order
      
      memset(hash, false, sizeof(hash));  // initialize boolean array 'hash'
      Dfs(bunch.length(), 0, "", bunch);
      cout << endl;
    }
  }// End of while
    
  return 0;
}

/*
PROG: 10300 - Ecological Premium
ID  : ouyangyewei
LANG: C++
*/
#include <iostream>

using namespace std;

namespace {

long ans;
int testCases, nFarmers, squares, nAnimals, envirPara;

}// namespace

int main() {
  cin >> testCases;
  while (testCases--) {
    ans = 0;
    cin >> nFarmers;
    for (int i = 0; i < nFarmers; ++i) {
      cin >> squares >> nAnimals >> envirPara;
      ans += (squares * envirPara);
    }
    
    cout << ans << endl;
  }// End of while
  
  return 0;
}

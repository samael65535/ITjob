#include <iostream>
#include <bitset>
#include <typeinfo>
#include <vector>
#include <stdexcept>
#include <assert.h>
using namespace std;
int main()
{
  int i = 100;
  // -DNDEBUG
// #ifndef NDEBUG 
//   assert(i < 100);
// #endif
  string s;
  while(cin >> s){
    assert(cin);
    cout << s << endl;
  }
  return 0;
}

#include <iostream>
#include <bitset>
#include <typeinfo>
using namespace std;

int main()
{
  string s = "1100";
  bitset<32> b(s);
  bitset<32> c("1100");// "1100" 是 char * 不像java一样会自动转变为string
  cout << b << endl;
  cout << b.reset() << endl;
  cout << b.set() << endl;
  cout << typeid(b).name() << endl;
  cout << b.test(2) << endl;
  char *s1 = "abcd";
  cout << s1 << endl;

  return 0;
}

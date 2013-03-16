#include <iostream>
using namespace std;
// 最大公约数qcd
int main()
{
  int v1, v2;
  cin >> v1 >> v2;
  while(v2){
    int temp = v2;
    v2 = v1 % v2;
    v1 = temp;
  }
  cout << temp;
  return 0;
}

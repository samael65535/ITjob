#include <iostream>
#include <vector>
using namespace std;
int main()
{
  vector<int> v(10, 12);
  for (vector<int>::iterator itr = v.begin(); itr != v.end(); ++itr){
    cout << *itr << endl;
    *itr = 0;
  }
  return 0;
}











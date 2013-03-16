#include <iostream>
#include <bitset>
#include <typeinfo>
#include <vector>
using namespace std;

int main()
{
  int *num_array = new int[10];
  int num2[10];
  cout << sizeof(num_array) << endl;
  num2[12] = 2;
  cout << sizeof(num2) << endl;
  cout << num2[12] << endl;
  return 0;

}

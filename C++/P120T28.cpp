#include <iostream>
#include <bitset>
#include <typeinfo>
#include <vector>
using namespace std;
// 编写一个vector对象, 然后动态创建一个与vector对象大小一样的数组, 把vector对象中所有元素复制给新数组
int main()
{
  vector<int> v(10, 10);
  int *pia = new int[v.size()];
  int i = 0;
  for (vector<int>::iterator itr = v.begin(); itr != v.end(); ++itr, ++i){
    pia[i] = *itr;
    cout << pia[i] << endl;
  }
  pia[12] = 100;

  cout << pia[12] << endl; // 注意长度
  delete[] pia;
  return 0;
}

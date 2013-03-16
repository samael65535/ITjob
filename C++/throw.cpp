#include <iostream>
#include <bitset>
#include <typeinfo>
#include <vector>
#include <stdexcept>
using namespace std;
// bitset类提供to_ulong操作
// 如果bitset提供的位数大于unsigned long的长度时
// 抛出一个overflow_error异常
int main()
{
  unsigned long ul;
  bitset<32> b;
  b.set();
  cout << b.size() << endl;
   try{
    if(b.size()/8 > sizeof(ul)/4 )
      throw overflow_error("ddd");
    b.to_ulong();
  }catch(overflow_error err){
    cout << "heheh" << endl;
  }
  return 0;
}

















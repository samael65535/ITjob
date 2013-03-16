#include <iostream>
#include <bitset>
#include <typeinfo>
#include <vector>
using namespace std;
// 定义一个vector对象, 其每个元素都是指向string类型的指针, 读取该vector对象, 输出每个string的内容及其相应在的长度
int main()
{
  vector<string> vtr;
  string str;
  while(1){
    getline(cin, str);
    if(str.size() != 0){
      vtr.push_back(str);
      cout << str.size() << endl;
    }
    else
      break;
  } 
  for(vector<string>::iterator itr = vtr.begin();
      itr != vtr.end(); ++itr)
    cout << (*itr).size() << endl;
  return 0;
}

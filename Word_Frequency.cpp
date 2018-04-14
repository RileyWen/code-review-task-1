#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <functional>
using namespace std;
int main()
{
  ifstream fin("./word.txt");//虽然这里几乎不可能出现打开文件异常的情况，但为了形成习惯还是应该检测一下
  map<string, size_t> word_count;
  string word;
  while (fin >> word)
    ++word_count[word];
//文件流使用结束后应该及时关闭
  typedef function<bool(pair<string, size_t>, pair<string, size_t>)> CmpType;
  CmpType Cmp = [](pair<string, size_t> a, pair<string, size_t> b) {
    return a.second > b.second;
  };

  set<pair<string, size_t>, CmpType> word_freq(word_count.begin(), word_count.end(), Cmp);
  for (auto element : word_freq)
    cout << element.first << " " << element.second << endl;
  return 0;
}

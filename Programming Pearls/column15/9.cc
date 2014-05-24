#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;
#include <iterator>
using std::ostream_iterator;
#include <algorithm>
using std::copy;

vector<string> LongestCommonString(const string &s, const string &t) {
  vector<vector<int> > array;
  int len_s = s.size();
  int len_t = t.size();
  int i, j;
  array.resize(len_s);
  for (i = 0; i < len_s; ++i) {
    array[i].resize(len_t);
  }
  int max_len = 0;
  vector<int> end_indexs;
  for (i = 0; i < len_s; ++i) {
    for (j = 0; j < len_t; ++j) {
      if (s[i] == t[j]) {
        if (i == 0 || j == 0) {
          array[i][j] = 1;
        } else {
          array[i][j] = array[i-1][j-1] + 1;
        }
        if (array[i][j] == max_len) {
          end_indexs.push_back(i);
        } else if (array[i][j] > max_len) {
          max_len = array[i][j];
          end_indexs.clear();
          end_indexs.push_back(i);
        }
      }
    }
  }
  vector<string> res;
  for (vector<int>::iterator it = end_indexs.begin(); it != end_indexs.end();
       ++it) {
    res.push_back(s.substr(*it - max_len + 1, max_len));
  }
  return res;
}
                  
        
int main(int argc, char *argv[]) {
  string s = "baaacd";
  string t = "aaarrrp[ewqr";
  vector<string> res;
  res = LongestCommonString(s, t);
  copy(res.begin(), res.end(), ostream_iterator<string>(cout, " "));
  cout << endl;
  s = "abcdwwwwhell";
  t = "hellqqqqabcd";
  res = LongestCommonString(s, t);
  copy(res.begin(), res.end(), ostream_iterator<string>(cout, " "));
  return 0;
}

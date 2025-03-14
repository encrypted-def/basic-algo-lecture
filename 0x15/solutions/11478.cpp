// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/53721d7a7c1d4eeebc912cba8930dcf1
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  unordered_set<string> uset;

  cin >> s;
  for (int st = 0; st < s.length(); st++)
    for (int len = 1; st + len <= s.length(); len++)
      uset.insert(s.substr(st, len));
  cout << uset.size();
}
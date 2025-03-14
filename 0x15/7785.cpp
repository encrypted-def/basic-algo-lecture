// http://boj.kr/b88f0e4817f94b0fa6080d56952fd1fe
#include <bits/stdc++.h>
using namespace std;

unordered_set<string> s;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  while(n--){
    string name, log;
    cin >> name >> log;
    if(log == "enter") s.insert(name);
    else s.erase(name);
  }
  vector<string> ans(s.begin(), s.end());
  sort(ans.begin(), ans.end(), greater<string>());
  for(auto x : ans) cout << x << '\n';
}
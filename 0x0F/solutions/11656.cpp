// Authored by : std-freejia
// Co-authored by : -
//http://boj.kr/21378a10916b42d19dce4bc7c841a73c
#include <bits/stdc++.h>
using namespace std;

string st;
vector<string> v;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> st;
  int stringlen = st.length();
  for(int i = 0; i < stringlen; i++) {
    string temp = st.substr(i);
    v.push_back(temp);
  }
  sort(v.begin(), v.end());
  for(auto i : v) cout << i << '\n';
  return 0;
}
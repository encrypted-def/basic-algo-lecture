// Authored by : tongnamuu
// Co-authored by : -
// http://boj.kr/00d1d9f7116b411fb7d50c1d8cf53823
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin>>s;
  int len = s.length();
  int cnt[2] = {0,0};
  cnt[s[0]-'0']++;
  for(int i=1;i<len;++i) if(s[i]!=s[i-1]) cnt[s[i]-'0']++;
  cout<<min(cnt[0], cnt[1]);
}

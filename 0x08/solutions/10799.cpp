// Authored by : BueVonHun
// Co-authored by : -
// http://boj.kr/926a4c383a464de3a85607a1d9db87a4
#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll ans = 0;
stack<char> st;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int sz = s.length();
  bool f = false;
  for (int i = 0; i < sz; i++) {
    if (s[i]=='(') {
      f = true;
      st.push(s[i]);
    }
    else if(s[i]==')') {
      if (f) {
        st.pop();
        ans+=st.size();
      }
      else {
        st.pop();
        ans++;
      }
      f = false;
    }
  }
  cout << ans << "\n";
  return 0;
}

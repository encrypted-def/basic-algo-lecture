// Authored by : haneulkimdev
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/6d1d0cec49bb4e0d94616c2ab82a3688
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    string a;
    cin >> a;
    stack<char> s;
    bool is_valid = true;
    for (auto c : a) {
      if (c == '(')
        s.push(c);
      else { // c == ')'
        if (s.empty() || s.top() != '(') {
          is_valid = false;
          break;
        }
        s.pop();
      }
    }
    if (!s.empty()) is_valid = false;
    
    if (is_valid) cout << "YES\n";
    else cout << "NO\n";
  }
}

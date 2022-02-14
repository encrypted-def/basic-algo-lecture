// Authored by : sukam09
// Co-authored by : -
// http://boj.kr/6e72b8d78bdf4935a713f079a03dc8ef
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  if (n == 0) {
    cout << 0;
    return 0;
  }
  while (n) {
    if (n < 0) {
      if (-n % 2 == 0) {
        n = -n / 2;
        v.push_back(0);
      }
      else {
        n = -n / 2 + 1;
        v.push_back(1);
      }
    }
    else {
      v.push_back(n % 2);
      n = -(n / 2);
    }
  }
  reverse(v.begin(), v.end());
  for (int i : v) cout << i;
}
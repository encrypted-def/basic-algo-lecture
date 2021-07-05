// Authored by : pha-ran (soft18)
// Co-authored by : -
// http://boj.kr/b8dd85f62e494e5585190f114bb59e45
#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  long long a, b;
  cin >> a >> b;
  if (a > b) swap(a, b);
  if (a == b || b - a == 1) cout << 0;
  else {
    cout << b - a - 1 << "\n";
    while (++a < b) cout << a << " ";
  }
}
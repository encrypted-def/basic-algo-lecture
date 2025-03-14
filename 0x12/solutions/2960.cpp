// Authored by : jihwan0123
// Co-authored by : -
// http://boj.kr/c980507acdc34d5ea79e397129f664c5
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<bool> state(n+1, true);
  for (int i=2; i<=n; i++){
    if (!state[i]) continue;
    for (int j=i; j<=n; j+=i){
      if (!state[j]) continue;
      state[j] = false;
      k--;
      if (k == 0){
        cout << j;
        return 0;
      }
    }
  }
}
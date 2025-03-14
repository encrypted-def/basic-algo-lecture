// Authored by : pha-ran (soft18)
// Co-authored by : -
// http://boj.kr/c2a05cf9d222441dba79bba4e9ac5b6e
#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int x, odd = 0, sum = 0, min = 100;

  for (int i = 0; i < 7; i++) {
    cin >> x;

    if (x & 1) {
      odd += 1;
      sum += x;

      if (x < min) {
        min = x;
      }
    }
  }

  if (odd) cout << sum << "\n" << min;
  else cout << "-1";
}
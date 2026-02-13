// Authored by : uhwan0723
// Co-authored by : -
// http://boj.kr/3712836049cd4e5fb51f27c9ad893b7a
#include <bits/stdc++.h>
using namespace std;

const int mn = 10;
int n, res = 1e9, a[mn], b[mn]; // a: 신 맛 배열, b: 쓴 맛 배열

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; ++i)
    cin >> a[i] >> b[i];
  for(int tmp = 1; tmp < (1<<n); ++tmp){
    int _a = 1, _b = 0; // _a: 신 맛의 곱, _b: 쓴 맛의 합
    for(int i = 0; i < n; ++i){
      if(!(tmp & (1 << i))) continue;
      _a *= a[i];
      _b += b[i];
    }
    res = min(res, abs(_a - _b));
  }
  cout << res;
}

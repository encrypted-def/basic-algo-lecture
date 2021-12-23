// Authored by : unluckyjung
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/64af97a2770445c3a53daa9403c1cf46
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int m, n;
int l[1000002];

// 막대 과자의 길이가 x일 경우 m조각 이상이 나오는가?
bool solve(int x) {
  if (x == 0) return true;
  ll cnt = 0;
  for (int i = 0; i < n; ++i) {
    cnt += l[i] / x;
  }
  return cnt >= m;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n;
  for (int i = 0; i < n; ++i)
    cin >> l[i];

  int st = 0;
  int en = *max_element(l, l+n);

  while (st < en) {
    int mid = (st + en + 1) / 2;
    if (solve(mid))
      st = mid;
    else
      en = mid - 1;
  }
  cout << st << "\n";
}

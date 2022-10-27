// Authored by : ZeroOnePro
// Co-authored by : -
// http://boj.kr/adda1088f8404374b8cca5329561a575
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
ll mx;
vector<ll> bud;

bool possible(int x) {
  if (x > mx) return false;
  ll sum = 0;
  for (auto b : bud) sum += (b <= x ? b : x);
  return sum <= m;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  bud.resize(n);
  for (auto& pt : bud) cin >> pt;
  cin >> m;
  int st = 0, en = 1e9 + 5;
  sort(bud.begin(), bud.end());
  mx = bud[n - 1];
  while (st < en) {
    int mid = (st + en + 1) / 2;
    if (possible(mid))
      st = mid;
    else
      en = mid - 1;
  }
  cout << st;
  return 0;
}

/*
 * 예산의 상한을 parametric search통해 설정한다
 * 입력으로 받은 예산 중 최대값보다 상한이 크거나 나눠줄 수 없는 경우 상한을 낮춘다
 * 설정한 상한으로 나눠줄 수 있을 때 최대를 찾기위해 상한을 높인다
*/
// Authored by : haneulkimdev
// Co-authored by : -
// http://boj.kr/ad7d6ee177654e6dbc83931bc7265b7a
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  int ans = 0;
  while (a != b) {
    a = (a + 1) / 2;
    b = (b + 1) / 2;
    ans++;
  }
  cout << ans;
}

/*
모든 참가자의 경기를 시뮬레이션하는 대신 두 명의 번호만 관리하는 풀이
*/

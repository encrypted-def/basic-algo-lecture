// Authored by : jihwan0123
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/f238e914a2b2492ba3bcff9f82879d63
#include <bits/stdc++.h>
using namespace std;

int d[1005][1005]; // d[i][j] : i개의 색 중 j개의 색 선택하는 경우의 수
const int mod = 1e9 + 3;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) d[i][1] = i; // i개중 1개 고르는 방법: i개
  for (int i = 4; i <= n; i++)
    for (int j = 2; j <= k; j++) {
      if (j > i / 2) break; // n개 중에서 n/2개 초과로 선택 불가
      // i-1개중 j개 선택 + n번째 색 선택 x
      // i-2개중 j-1개 선택 + n번째 색 선택 o
      d[i][j] = (d[i - 1][j] + d[i - 2][j - 1]) % mod;
    }
  cout << d[n][k];
}

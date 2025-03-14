// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/2422d605017041259db67ccc36416aad
#include <bits/stdc++.h>
using namespace std;

int N, ans;
int P[1002];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> P[i];
  sort(P, P + N);
  for (int i = 0; i < N; i++) ans += P[i] * (N - i);
  cout << ans;
}
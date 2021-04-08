// Authored by : JaeraeKim
// Co-authored by : -
// http://boj.kr/e0b425a934924e3da795d4e0c7e61b7c
#include <bits/stdc++.h>
using namespace std;

int step[305];
int dp[305];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> step[i];
  dp[1] = step[1];
  if (n > 1) dp[2] = step[2] + step[1];
  if (n > 2) dp[3] = step[3] + max(step[2], step[1]);
  for (int i = 4; i <= n; i++)
    dp[i] = step[i] + max(step[i - 1] + dp[i - 3], dp[i - 2]);
  cout << dp[n];
  return 0;
}

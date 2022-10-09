// Authored by : sukam09
// Co-authored by : -
// http://boj.kr/dbefaf747b2c419a9386b9f9cb1e1e1a
#include <bits/stdc++.h>
using namespace std;

int a[1005];
int d[1005][35];  // d[t][w]에서 t는 자두가 떨어진 시간, w는 자두가 움직인 횟수

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int t, w;
  cin >> t >> w;
  for (int i = 1; i <= t; i++) cin >> a[i];
  
  // 자두가 한 번도 움직이지 않았을 때
  int cnt = 0;
  for (int i = 1; i <= t; i++) {
    if (a[i] == 1) cnt++;
    d[i][0] = cnt;
  }

  for (int i = 1; i <= t; i++)
    for (int j = 1; j <= w; j++)
      // 자두가 움직인 횟수가 홀수일 경우 2번 나무, 짝수일 경우 1번 나무에 가게 된다.
      d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + (1 + j % 2 == a[i]);
  
  cout << *max_element(d[t], d[t] + w + 1);
}
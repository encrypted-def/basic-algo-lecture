// Authored by : haneulkimdev
// Co-authored by : -
// http://boj.kr/844f77ac02c84f889eeb69a5cf7d652b
#include <bits/stdc++.h>
using namespace std;

int paper[128][128];
int ans[2];

bool chk(int n, int x, int y) {
  for (int i = x; i < x + n; i++)
    for (int j = y; j < y + n; j++)
      if (paper[i][j] != paper[x][y]) return false;
  return true;
}

void func(int n, int x, int y) {
  if (chk(n, x, y)) {
    ans[paper[x][y]]++;
    return;
  }
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) func(n / 2, x + i * n / 2, y + j * n / 2);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> paper[i][j];
  func(n, 0, 0);
  for (int i = 0; i < 2; i++) cout << ans[i] << '\n';
}

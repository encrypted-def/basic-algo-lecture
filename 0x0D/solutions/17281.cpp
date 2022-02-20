// Authored by : SciEm
// Co-authored by : -
// http://boj.kr/35a08f4f67bc4df2803469b472ffebe4
#include <bits/stdc++.h>
using namespace std;

int board[51][9];
int order[9];
bool isused[9];
int n, ans;

void run() {
  int score = 0;
  int idx = 0;
  for (int inning = 0; inning < n; inning++) {
    bool bases[4] = {};
    int out = 0;
    while (out < 3) {
      bases[0] = true;
      int move = board[inning][order[idx++]];
      if (idx == 9) idx = 0;
      if (!move) {
        out++;
        continue;
      }
      for (int i = 3; i >= 0; i--) {
        if (!bases[i]) continue;
        if (i + move >= 4) score++;
        else bases[i + move] = true;
        bases[i] = false;
      }
    }
  }
  ans = max(ans, score);
}

void brute(int k) {
  if (k == 9) {
    run();
    return;
  }
  if (k == 3) {
    brute(k + 1);
    return;
  }
  for (int i = 1; i < 9; i++) {
    if (isused[i]) continue;
    order[k] = i;
    isused[i] = true;
    brute(k + 1);
    isused[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 9; j++)
      cin >> board[i][j];

  brute(0);
  cout << ans;
}

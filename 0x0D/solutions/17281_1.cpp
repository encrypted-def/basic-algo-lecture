// Authored by : SciEm
// Co-authored by : -
// http://boj.kr/885bdec0716d40568722fae2cb8b2d84
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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 9; j++)
      cin >> board[i][j];

  int arr[8];
  for (int i = 0; i < 8; i++)
    arr[i] = i + 1;
  order[3] = 0;
  
  do {
    copy(arr, arr + 3, order);
    copy(arr + 3, arr + 8, order + 4);
    run();
  } while (next_permutation(arr, arr + 8));
  cout << ans;
}

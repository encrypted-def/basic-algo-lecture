// Authored by : SciEm
// Co-authored by : -
// http://boj.kr/8ec01fe1e1244dcd8e6bea1a2b4d547f
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int nums[12];
bool ladder[32][12];
pair<int, int> brute[3];
int n, m, h;

void run() {
  // 초기화
  for (int i = 1; i <= n; i++)
    nums[i] = i;
  // 사다리 타기
  for (int i = 1; i <= h; i++)
    for (int j = 1; j < n; j++)
      if (ladder[i][j]) swap(nums[j], nums[j + 1]);
}

// i번째가 i인지 확인
bool check() {
  for (int i = 1; i <= n; i++)
    if (nums[i] != i) return false;
  return true;
}

// 최대 깊이 l, 현재 깊이 k의 dfs
void backtracking(int l, int k) {
  if (k == l) {
    run();
    if (check()) {
      cout << l;
      exit(0);
    }
    return;
  }
  // 행의 시작점 x_st
  int x_st = k ? (brute[k - 1].Y == n - 1 ? brute[k - 1].X + 1 : brute[k - 1].X) : 1;
  for (int i = x_st; i <= h; i++) {
    // 열의 시작점 y_st
    int y_st = (k && brute[k - 1].X == i) ? brute[k - 1].Y + 1 : 1;
    for (int j = y_st; j < n; j++) {
      if (ladder[i][j - 1] || ladder[i][j] || ladder[i][j + 1]) continue;
      brute[k] = {i, j};
      ladder[i][j] = true;
      backtracking(l, k + 1);
      ladder[i][j] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> h;
  while (m--) {
    int a, b;
    cin >> a >> b;
    ladder[a][b] = true;
  }

  for (int l = 0; l <= 3; l++)
    backtracking(l, 0);
  cout << -1;
}

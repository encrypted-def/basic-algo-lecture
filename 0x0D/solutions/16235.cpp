// Authored by : SciEm
// Co-authored by : -
// http://boj.kr/edd3300dccf34b009ee9345fc1905003
#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int field[12][12];
int S2D2[12][12];
// 각 좌표별로 나무의 나이를 deque에 저장
deque<int> tree[12][12];
int n, m, k;

void run1(int x, int y) {
  auto& dq = tree[x][y];
  // 봄
  auto it = dq.begin();
  for (; it != dq.end() && *it <= field[x][y]; it++)
    field[x][y] -= (*it)++;
  auto tmp = it;
  // 여름
  for (; it != dq.end(); it++)
    field[x][y] += *it / 2;
  dq.erase(tmp, dq.end());
}

void run2(int x, int y) {
  // 가을
  for (auto age : tree[x][y])
    if (!(age % 5))
      for (int dir = 0; dir < 8; dir++)
        tree[x + dx[dir]][y + dy[dir]].push_front(1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      field[i][j] = 5;
      cin >> S2D2[i][j];
    }
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    tree[x][y].push_front(z);
  }

  while (k--) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        run1(i, j);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        run2(i, j);
        // 겨울
        field[i][j] += S2D2[i][j];
      }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      ans += tree[i][j].size();
  cout << ans;
}

// Authored by : SciEm
// Co-authored by : -
// http://boj.kr/e3d3c8665e4c499b9c591afa0ae78916
#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int field[12][12];
int S2D2[12][12];
// 각 좌표별로 나무의 나이를 벡터에 저장
vector<int> tree[12][12];
int n, m, k;

void run1(int x, int y) {
  auto& v = tree[x][y];
  // 봄
  auto rit = v.rbegin();
  for (; rit != v.rend() && *rit <= field[x][y]; rit++)
    field[x][y] -= (*rit)++;
  auto vend = rit.base();
  // 여름
  for (; rit != v.rend(); rit++)
    field[x][y] += *rit / 2;
  v.erase(v.begin(), vend);
}

void run2(int x, int y) {
  // 가을
  for (auto age : tree[x][y])
    if (!(age % 5))
      for (int dir = 0; dir < 8; dir++)
        tree[x + dx[dir]][y + dy[dir]].push_back(1);
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
    tree[x][y].push_back(z);
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

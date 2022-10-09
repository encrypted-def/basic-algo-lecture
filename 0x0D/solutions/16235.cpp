// Authored by : SciEm
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/a8b4cfe4ec394b73877d7f3c316bdf50
#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int field[12][12];
int S2D2[12][12];
vector<int> tree[12][12]; // 나무의 나이를 벡터에 저장
int n, m, k;

void run1(int x, int y) {
  auto& v = tree[x][y];
  // 봄
  int idx = (int)v.size() - 1;
  for(; idx >= 0; idx--){
    if(field[x][y] < v[idx]) break;
    field[x][y] -= v[idx];
    v[idx]++;
  }
  // v[idx..0]에는 봄에 죽은 나무가 저장됨
  // 여름
  for(int i = 0; i <= idx; i++)
    field[x][y] += v[i] / 2;
  
  v.erase(v.begin(), v.begin() + idx + 1);
}

void run2(int x, int y) {
  // 가을
  for (auto age : tree[x][y])
    if (!(age % 5))
      for (int dir = 0; dir < 8; dir++)
        tree[x + dx[dir]][y + dy[dir]].push_back(1);
  // 겨울
  field[x][y] += S2D2[x][y];
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
      for (int j = 1; j <= n; j++)
        run2(i, j);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      ans += tree[i][j].size();
  cout << ans;
}
// tree vector에는 반드시 나무가 나이에 대한 내림차순으로 저장이 되어 있다.

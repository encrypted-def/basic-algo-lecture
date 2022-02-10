// Authored by : sukam09
// Co-authored by : -
// http://boj.kr/42ba0a9f34074a6aab7c8dd4430ddcd4
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m, d;
int arr[20][20]; // 원본 격자판
int a[20][20]; // 시뮬레이션을 돌릴 때 사용하는 격자판
int enemy;
vector<pair<int, int>> epos;

int dist(int i, int j, int arow, int acol) {
  return abs(i - arow) + abs(j - acol);
}

void shoot(int arow, int x, int y, int z) {
  epos.clear();
  for (int acol : {x, y, z}) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    for (int i = 0; i < arow; i++) {
      for (int j = 0; j < m; j++)
        if (a[i][j] && dist(i, j, arow, acol) <= d)
          pq.push({dist(i, j, arow, acol), j, i});
    }
    if (!pq.empty()) {
      int dd, yy, xx;
      tie(dd, yy, xx) = pq.top();
      epos.push_back({xx, yy});
    }
  }
}

int solve(int i, int j, int k) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      a[i][j] = arr[i][j];

  int arow = n;
  int ret = 0;
  int e = enemy;

  // 한 번의 턴이 끝나고 적이 아래로 이동하는 과정을 궁수가 올라가는 과정으로 대신 표현
  while (e) {
    shoot(arow, i, j, k);
    for (auto cur : epos) {
      int xx = cur.X, yy = cur.Y;
      if (a[xx][yy]) {
        a[xx][yy] = 0;
        e--; ret++;
      }
    }
    // 궁수가 곧 올라갈 칸이며 성이 있는 칸으로 간주되어 게임에서 제외됨
    for (int col = 0; col < m; col++)
      if (a[arow - 1][col]) a[arow - 1][col] = 0, e--;
    arow--;
  }
  return ret;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m >> d;
  for (int i = 0; i < n ; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j]) enemy++;
    }
  }
  
  int ans = 0;
  for (int i = 0; i < m; i++)
    for (int j = i + 1; j < m; j++)
      for (int k = j + 1; k < m; k++)
        ans = max(ans, solve(i, j, k));
  
  cout << ans;
}
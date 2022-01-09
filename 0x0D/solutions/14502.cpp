// Authored by : jihwan0123
// Co-authored by : -
// http://boj.kr/b731c561481a4a63a9b219d3f85af07e
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int arr[8][8];
int og_arr[8][8]; // 원본
int n, m, ans;
int free_cells = -3;
queue<pair<int, int>> virus;  // 바이러스
vector<pair<int, int>> frees; // 빈칸
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs(queue<pair<int, int>> q) {
  int ret = 0;
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    ret++;
    for (int i = 0; i < 4; i++) {
      int nx = cur.X + dx[i];
      int ny = cur.Y + dy[i];
      if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if (arr[nx][ny] == 0) {
        arr[nx][ny] = 2;
        q.push({nx, ny});
      }
    }
  }
  return ret;
}

void dfs(int k) {
  // 벽 3개 세웠으면 bfs로 확인
  if (k == 3) {
    // 바이러스 퍼진 개수 체크
    int tmp = bfs(virus);
    // 안전영역 = 빈칸 - 바이러스 퍼진 칸
    ans = max(free_cells - tmp + (int)virus.size(), ans);
    // 원본으로 돌려놓기
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        arr[i][j] = og_arr[i][j];
    return;
  }
  // 빈 칸 벽으로 변경해본다.
  for (auto f : frees) {
    if (arr[f.X][f.Y] == 1) continue;
    arr[f.X][f.Y] = og_arr[f.X][f.Y] = 1;
    dfs(k + 1);
    arr[f.X][f.Y] = og_arr[f.X][f.Y] = 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      og_arr[i][j] = arr[i][j]; // 원본 저장
      if (arr[i][j] == 0) {     // 빈 칸 개수와 좌표 저장
        free_cells++;
        frees.push_back({i, j});
      } else if (arr[i][j] == 2) // 바이러스 좌표 저장
        virus.push({i, j});
    }
  }
  dfs(0);
  cout << ans;
}
/*
빈칸 중에서 3개씩 벽으로 바꿔보면서 최대 크기 계산
*/
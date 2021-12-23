// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/26322cc46f674b9faf8bb7227c864284
#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

bool mask[25];
string board[5];
int ans, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 5; i++)
    cin >> board[i];

  // 25명중 칠공주가 될 사람의 후보 조합을 뽑습니다.
  for (int i = 7; i < 25; i++) mask[i] = true;
  do {
    queue<PII> q;
    // 구성원 중 이다솜파의 수, 가로세로로 인접한 사람의 수
    int dasom = 0, adj = 0;
    bool isp7[5][5] = {}, vis[5][5] = {};
    for (int i = 0; i < 25; i++)
      if (!mask[i]) {
        int x = i / 5, y = i % 5;
        isp7[x][y] = true;
        if (q.empty()) {
          q.push({x, y});
          vis[x][y] = true;
        }
      }
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      adj++;
      dasom += board[x][y] == 'S';
      for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || vis[nx][ny] || !isp7[nx][ny])
          continue;
        q.push({nx, ny});
        vis[nx][ny] = true;
      }
    }
    ans += (adj >= 7 && dasom >= 4);

  } while (next_permutation(mask, mask + 25));
  cout << ans;
}
/*
25명 중 칠공주가 배치될 수 있는 모든 조합을 시도합니다.
경우의 수가 많아보이지만, 25C7 = 480700이므로
충분히 2초안에 수행될 수 있습니다.
서로 가로세로로 인접해야 한다는 2번 조건은 여러가지 방법으로
확인할 수 있으나, 본 풀이에서는 BFS를 이용하였습니다.
*/
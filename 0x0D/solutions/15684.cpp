// Authored by : SciEm
// Co-authored by : -
// http://boj.kr/86f2dbc3aaf549e1a41a104623c74e6a
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

bool ladder[32][12];
int idxs[3];
vector<pair<int, int>> coords;  // 고를 수 있는 가로선만을 저장할 벡터
int n, m, h;

// i번째가 i인지 사다리를 타며 확인
bool check() {
  for (int j = 1; j <= n; j++) {
    int cur = j;
    for (int i = 1; i <= h; i++) {
      if (ladder[i][cur - 1]) cur--;
      else if (ladder[i][cur]) cur++; 
    }
    if (cur != j) return false;
  }
  return true;
}

void backtracking(int l, int k) {
  if (k == l) {
    if (check()) {
      cout << l;
      exit(0);
    }
    return;
  }
  int st = 0;
  if (k) {
    if (coords[idxs[k - 1]].Y == n - 1)  // 이전 선택이 마지막 열이면
      st = idxs[k - 1] + 1;              // 그 다음 좌표(다음 행, 첫 열)부터 시작해도 인접하지 않음
    else st = idxs[k - 1] + 2;           // 아니면 다다음 좌표부터
  }
  for (int i = st; i < coords.size(); i++) {
    idxs[k] = i;
    ladder[coords[i].X][coords[i].Y] = true;
    backtracking(l, k + 1);
    ladder[coords[i].X][coords[i].Y] = false;
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

  for (int i = 1; i <= h; i++)
    for (int j = 1; j < n; j++) {
      // 인접한 것은 애초에 넣지 않음
      if (ladder[i][j - 1] || ladder[i][j] || ladder[i][j + 1]) continue;
      coords.push_back({i, j});
    }

  for (int l = 0; l <= 3; l++)
    backtracking(l, 0);
  cout << -1;
}

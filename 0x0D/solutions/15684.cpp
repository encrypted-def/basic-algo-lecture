// Authored by : SciEm
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/74da3b10100849d68340661e3e748159
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


  if(check()){
    cout << 0;
    return 0;
  }

  int ans = 0x7f7f7f7f;
  int sz = coords.size();
  for(int i = 0; i < sz; i++){
    ladder[coords[i].X][coords[i].Y] = true;
    if(check()) ans = min(ans, 1);
    for(int j = i+1; j < sz; j++){
      ladder[coords[j].X][coords[j].Y] = true;
      if(check()) ans = min(ans, 2);
      for(int k = j+1; k < sz; k++){
        ladder[coords[k].X][coords[k].Y] = true;
        if(check()) ans = min(ans, 3);
        ladder[coords[k].X][coords[k].Y] = false;
      }
      ladder[coords[j].X][coords[j].Y] = false;
    }
    ladder[coords[i].X][coords[i].Y] = false;
  }
  if(ans == 0x7f7f7f7f) ans = -1;
  cout << ans;
}
/*
3중 for문 대신 백트래킹을 써도 됨
*/

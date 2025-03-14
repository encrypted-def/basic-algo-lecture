// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/18c960450d304b84acf73c428d093b2e
#include <bits/stdc++.h>
using namespace std;

const int MXN = 100'010, ROOT = 1;
int N, a, b, c, lc[MXN], rc[MXN], p[MXN];
vector<bool> vis(MXN);
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  p[ROOT] = -1;
  for (int i = 0; i < N; i++) {
    cin >> a >> b >> c;
    lc[a] = b;
    rc[a] = c;
    p[b] = a;
    p[c] = a;
  }
  int endpoint = ROOT;
  // 중위순회의 끝 점은 가장 오른쪽에 있는 노드입니다.
  while (rc[endpoint] != -1)
    endpoint = rc[endpoint];

  int cur = ROOT, move = 0;
  while (1) {
    vis[cur] = true;
    move++;
    if (lc[cur] != -1 && !vis[lc[cur]])
      cur = lc[cur];
    else if (rc[cur] != -1 && !vis[rc[cur]])
      cur = rc[cur];
    else {
      if (cur == endpoint)
        break;
      else
        cur = p[cur];
    }
  }
  cout << move - 1;
}
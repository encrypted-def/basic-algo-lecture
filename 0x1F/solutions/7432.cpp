// Authored by : sukam09
// Co-authored by : -
// http://boj.kr/a0dadd213ec1458fbf61dd335f06a9ac
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int MX = 500 * 40 + 5;
const int ROOT = 1;
int unused = 2;
unordered_map<string, int> nxt[MX];  // nxt[v][r] -> v번 노드의 자식 중 이름이 r인 노드의 번호
int depth[MX];                       // 노드의 깊이를 나타내며 ROOT의 깊이는 -1로 정의
string name[MX];                     // 노드의 이름

void insert(vector<string>& route) {
  int v = ROOT;
  for (auto r : route) {
    int nv = nxt[v][r];
    if (nv == 0)
      nv = nxt[v][r] = unused++;
    depth[nv] = depth[v] + 1;
    name[nv] = r;
    v = nv;
  }
}

void dfs(int v) {
  if (v != ROOT) {
    for (int i = 0; i < depth[v]; i++) cout << ' ';
    cout << name[v] << '\n';
  }
  // nxt[v]가 unordered map이므로 vector로 바꾼 뒤 노드 이름을 이용해서 sort
  vector<pair<string, int>> m(nxt[v].begin(), nxt[v].end());
  sort(m.begin(), m.end());
  for (auto mm : m) dfs(mm.Y);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  depth[ROOT] = -1;
  while (n--) {
    string s;
    cin >> s;
    string cur = "";
    vector<string> route;
    // "\"를 기준으로 split하여 route에 삽입
    for (auto c : s) {
      if (c == '\\') {
        route.push_back(cur);
        cur = "";
      } else
        cur += c;
    }
    route.push_back(cur);
    insert(route);
  }
  dfs(ROOT);
}

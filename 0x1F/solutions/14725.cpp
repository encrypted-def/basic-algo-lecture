// Authored by : Joshua-Shin
// Co-authored by : -
// http://boj.kr/05e6530bfdb74e16bcedecd7da39b0f9
#include <bits/stdc++.h>
using namespace std;

const int MX = 1000 * 15 + 5;
map<string, int> nxt[MX];
int root = 1;
int unused = 2;
void insert(vector<string> &v) {
  int cur = root;
  for (auto s : v) {
    if (!nxt[cur][s])
      nxt[cur][s] = unused++;
    cur = nxt[cur][s];
  }
}
void dfs(int cur, int d) {
  for (auto nx : nxt[cur]) {
    string level;
    for (int i = 0; i < d; i++)
      level += "--";
    cout << level << nx.first << '\n';
    dfs(nx.second, d + 1);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    vector<string> inputStr(m);
    for (int i = 0; i < m; i++)
      cin >> inputStr[i];
    insert(inputStr);
  }
  dfs(1, 0);
}

/*
일반 트리이 문제처럼 한글자 단위로 저장하는것이 아니라 문자열을 통째로 저장한다.
또한 사전 편찬순으로 출력해야 하기에 nxt[MX]을 Map 자료구조로 선언한다.
nxt[cur][s] = 현재 정점번호가 cur이고, 자식노드 중 문자열이 s인 노드의 정점 번호.
*/

// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/ba2ccffa99514399aebf4bcc9e391a48
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[100001];
int p[100001];

void dfs(int cur) {
  for (int nxt : adj[cur]) {
    if (p[cur] == nxt) continue;
    p[nxt] = cur;
    dfs(nxt);
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n-1; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1);
  for(int i = 2; i <= n; i++) cout << p[i] << '\n';
}
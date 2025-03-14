// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/9205a3a58c764ea49b7d40ccc012481c
#include <bits/stdc++.h>
using namespace std;

int n;

bool am[102][102];
bool vis[102];

bool dfs(int st, int tar) {
  fill(vis, vis + n + 2, 0);
  stack<int> stk;
  stk.push(st);

  while(!stk.empty()) {
    int cur = stk.top();
    stk.pop();

    if(vis[cur]) continue;
    if(cur != st) vis[cur] = 1;

    for(int nxt = 0; nxt < n; nxt++) {
      if(vis[nxt]) continue;
      if(am[cur][nxt]) {
        if(nxt == tar) return true;
        stk.push(nxt);
      }
    }
  }
  return false;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> am[i][j];
  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
      cout << dfs(i, j) << ' ';
    cout << '\n';
  }
}
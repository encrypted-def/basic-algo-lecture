// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/131d930506174c38a8f03cc187885c75
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[52];
vector<pair<int, int>> candsc;
int score[52];

int bfs(int st){
  queue<int> q;
  fill(score, score + n + 2, -1);

  score[st] = 0;
  q.push(st);
  while(!q.empty()) {
    int cur = q.front(); q.pop();
    for(int fr : adj[cur]) {
      if(score[fr] != -1) continue;
      score[fr] = score[cur] + 1;
      q.push(fr);
    }
  }
  int mxidx = max_element(score + 1, score + n + 1) - score;
  if(score[mxidx] == 0) return 100;
  else return score[mxidx];
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  int u = 0, v = 0;
  while(u != -1 && v != -1) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int i = 1; i <= n; i++)
    candsc.push_back({bfs(i), i});
  sort(candsc.begin(), candsc.end());

  vector<int> cand;
  auto it = candsc.begin();
  int minsc = (*it).first;
  cand.push_back((*it).second);
  it++;

  int cnt = 1;
  while(it != candsc.end()) {
    int sc = (*it).first;
    if(sc != minsc) break;
    cand.push_back((*it).second);
    it++; cnt++;
  }

  cout << minsc << ' ' << cnt << '\n';
  for(int c : cand) cout << c << ' ';
}
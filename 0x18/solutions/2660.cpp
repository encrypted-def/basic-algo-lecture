// Authored by : scsc3204
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/ac7620713b584538a952a5d919324cbb
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[52];
vector<pair<int, int>> candsc;
int score[52]; // 각 사람의 점수

int bfs(int st){ // st의 점수 계산
  queue<int> q;
  int dist[52];
  fill(dist, dist+n+1, -1);

  dist[st] = 0;
  q.push(st);
  while(!q.empty()) {
    int cur = q.front(); q.pop();
    for(int fr : adj[cur]) {
      if(dist[fr] != -1) continue;
      dist[fr] = dist[cur] + 1;
      q.push(fr);
    }
  }
  int val = *max_element(dist + 1, dist + n + 1); // 가장 거리가 먼 사람
  if(val == 0) return 100; // 친구가 아예 없으면 val은 0이 됨
  return val;
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
    score[i] = bfs(i);
  
  int mnscore = *min_element(score+1, score+n+1);
  vector<int> cand; // 후보 목록
  for(int i = 1; i <= n; i++){
    if(score[i] == mnscore)
      cand.push_back(i);
  }

  cout << mnscore << ' ' << cand.size() << '\n';
  for(int c : cand) cout << c << ' ';
}

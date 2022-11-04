// Authored by : scsc3204
// Co-authored by : BaaaaaaaaaaarkingDog	
// http://boj.kr/94d8ab3641884643ae3aeb2f2c10d853
#include <bits/stdc++.h>
using namespace std;

int n, m, t;
vector<int> pt[52];
vector<int> adj[52];
bool tr[52]; // 진실을 아는지 여부

// 굳이 vis 배열을 쓸 필요 없이 tr을 vis처럼 쓰면 됨
void bfs() {
  queue<int> q;
  for(int i = 1; i <= n; i++)
    if(tr[i]) q.push(i);
  
  while(!q.empty()) {
    int cur = q.front(); q.pop();
    for(int nxt : adj[cur]) {
      if(tr[nxt]) continue;
      tr[nxt] = 1;
      q.push(nxt);
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> t;
  while(t--) {
    int x; cin >> x;
    tr[x] = 1;
  }

  for(int i = 0; i < m; i++) {
    int no; cin >> no;

    int prv, nxt;
    cin >> prv;
    pt[i].push_back(prv);

    while(--no) {
      cin >> nxt;
      pt[i].push_back(nxt);
      adj[nxt].push_back(prv);
      adj[prv].push_back(nxt); // 동일한 파티에 참석한 앞뒤 사람끼리 간선이 연결되어있다고 생각
      swap(prv, nxt);
    }
  }

  bfs(); // bfs를 돌리면 간선을 통해 연결된 사람들에게로 진실이 전파됨

  int cnt = 0;
  for(int i = 0; i < m; i++) {
    bool known = 0; // 진실을 아는 사람이 파티 내에 있는지
    for(int p : pt[i]) if(tr[p]) known = 1;
    if(!known) cnt++;
  }
  cout << cnt;
}

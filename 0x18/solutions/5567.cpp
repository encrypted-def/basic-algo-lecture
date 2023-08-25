// Authored by : yongjunleeme
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/65c65de75cb34088b63463ec29b4e92a
#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
vector <int> adj[505];
int vis[505];
int ans = 0;

void dfs(){
  stack<int> s;
  s.push(1);
  while(!s.empty()){
    int cur = s.top(); s.pop();
    vis[cur] = 1;
    for(auto nxt : adj[cur]){
      if(vis[nxt]) continue;
      vis[nxt] = 1;
      ans++;
      if(cur == 1) s.push(nxt); // 상근이의 이웃만 스택에 추가됨
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while(m--){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs();
  cout << ans;
}

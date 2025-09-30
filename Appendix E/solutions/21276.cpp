// Authored by : uhwan0723
// Co-authored by : -
// http://boj.kr/e2d7dbb7a5544968a61c8d7dfaaffd97
#include <bits/stdc++.h>
using namespace std;

int n, m;
map<string, vector<string>> adj, childs; // adj[name] = name의 모든 후손들, childs[name] = name의 자식들
map<string, int> indeg;
map<string, string> par; // par[name] = name의 1대 조상
vector<string> names;
queue<string> q;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  string s;
  for(int i = 0; i < n; ++i){
    cin >> s;
    names.push_back(s);
  }
  sort(names.begin(), names.end());
  cin >> m;
  while(m--){
    string ch, anc;
    cin >> ch >> anc;
    adj[anc].push_back(ch);
    ++indeg[ch];
  }

  // 큐에 들어간 indegree가 0인 정점들 = 각 가문의 시조들
  for(string name : names)
    if(indeg[name] == 0) q.push(name);
  cout << q.size() << '\n';
  for(int i = 0; i < q.size(); ++i){
    string name = q.front(); q.pop();
    cout << name << ' ';
    q.push(name);
  }
  cout << '\n';
  
  while(!q.empty()){
    string cur = q.front(); q.pop();
    for(string nxt : adj[cur]){
      // nxt의 par[nxt]값은 여러 번 갱신될 수 있으나, nxt의 1대 조상이 큐에 들어갈 때 마지막으로 갱신된다.
      par[nxt] = cur;
      if(--indeg[nxt] == 0) q.push(nxt);
    }
  }
  
  for(string name : names)
    childs[par[name]].push_back(name);
  
  for(string name : names){
    cout << name << ' ' << childs[name].size() << ' ';
    for(string ch : childs[name])
      cout << ch << ' ';
    cout << '\n';
  }
}

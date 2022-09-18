// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/2259e4b16e2241b19bb31f1734a9b489
#include <bits/stdc++.h>
using namespace std;

int n, m;
string s1, s2;

string name[1002];
unordered_map<string, int> id;

int indeg[1002];
vector<int> adj[1002];
vector<int> ch[1002];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> name[i];
  sort(name + 1, name + n + 1);

  for(int i = 1; i <= n; i++)
    id[name[i]] = i;

  cin >> m;
  for(int i = 0; i < m; i++) {
    cin >> s1 >> s2;
    adj[id[s2]].push_back(id[s1]);
    indeg[id[s1]]++;
  }

  vector<int> ac;
  for(int i = 1; i <= n; i++)
    if(!indeg[i]) ac.push_back(i);

  cout << ac.size() << '\n';
  for(int a : ac)
    cout << name[a] << ' ';
  cout << '\n';

  for(int i = 1; i <= n; i++)
    sort(adj[i].begin(), adj[i].end());

  for(int i = 1; i <= n; i++)
    for(int c : adj[i])
      if(indeg[c] - indeg[i] == 1) ch[i].push_back(c);

  for(int i = 1; i <= n; i++) {
    int sz = ch[i].size();
    cout << name[i] << ' ' << sz << ' ';
    for(int c : ch[i])
      cout << name[c] << ' ';
    cout << '\n';
  }
}
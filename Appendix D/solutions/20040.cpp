// Authored by : uhwan0723
// Co-authored by : -
// http://boj.kr/f654dc349b074299a388938b0c5b35a8
#include <bits/stdc++.h>
using namespace std;

const int mn = 500005;
int res, n, m, par[mn];

int find(int x){
  if(par[x] < 0) return x;
  return par[x] = find(par[x]);
}

bool uni(int x, int y){
  int u = find(x), v = find(y);
  if(u == v) return false;
  if(-par[u] < -par[v]) std::swap(u, v);
  if(par[u] == par[v]) --par[u];
  par[v] = u;
  return true;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  fill(par, par+n+1, -1);
  while(m--){
    ++res;
    int u, v;
    cin >> u >> v;
    if(!uni(u, v)){
      cout << res;
      return 0;
    }
  }
  cout << 0;
}

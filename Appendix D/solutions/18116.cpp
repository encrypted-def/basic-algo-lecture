// Authored by : uhwan0723
// Co-authored by : -
// http://boj.kr/23f94068108e4bdba086c2b011dc5a3a
#include <bits/stdc++.h>
using namespace std;

const int mx = 1e6+5;
int n, a, b, c, par[mx], sz[mx];

int find(int x){
  if(par[x] < 0) return x;
  return par[x] = find(par[x]);
}

void uni(int x, int y){
  int u = find(x), v = find(y);
  if(u == v) return;
  if(-par[u] < -par[v]) swap(u, v);
  if(par[u] == par[v]) --par[u];
  par[v] = u;
  sz[u] += sz[v];
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  fill(par, par+mx, -1);
  fill(sz, sz+mx, 1);
  while(n--){
    char command;
    cin >> command;
    if(command == 'I'){
      cin >> a >> b;
      uni(a, b);
    }
    else{
      cin >> c;
      cout << sz[find(c)] << '\n';
    }
  }
}

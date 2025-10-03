// Authored by : uhwan0723
// Co-authored by : -
// http://boj.kr/6baaf9ffbfe746fd88488265801717b4
#include <bits/stdc++.h>
using namespace std;

const int mn = 1e6+5;
int n, m, par[mn], nxt[mn];
/*
nxt[i]: i번 방이 속해있는 집합에 속하지 않으면서, 그 집합의 오른쪽에 위치하고, 그 중에서 번호가 가장 낮은 방
예를 들어 i, i+1이 한 집합이면 nxt[i] = nxt[i+1] = i+2
초기에 각 방은 자기 자신만 있는 집합에 속하기 때문에, nxt[i]의 초기값은 i+1
*/

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
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  fill(par, par+n+5, -1);
  fill(nxt, nxt+n+5, mn);
  for(int i = 1; i <= n; ++i)
    nxt[i] = i+1;
  while(m--){
    int x, y;
    cin >> x >> y;
    for(int i = nxt[find(x)]; i <= y; i = nxt[find(i)]){
      nxt[find(x)] = nxt[find(i)];
      uni(x, i);
    }
  }
  int res = 0;
  for(int i = 1; i <= n; ++i)
    res += par[i] < 0;
  cout << res;
}

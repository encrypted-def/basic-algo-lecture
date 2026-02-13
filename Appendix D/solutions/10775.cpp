// Authored by : uhwan0723
// Co-authored by : -
// http://boj.kr/0a35dfe1f769483cb900acbd7757b1fb
#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+5;
int G, P, res, par[mx];

int find(int x){
  if(par[x] < 0) return x;
  return par[x] = find(par[x]);
}

void uni(int x, int y){
  int u = find(x), v = find(y);
  if(u == v) return;
  par[u] = v;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> G >> P;
  fill(par, par+G+5, -1);
  while(P--){
    int g;
    cin >> g;
    int idx = find(g);
    if(idx == 0) break;
    uni(g, idx-1);
    ++res;
  }
  cout << res;
}

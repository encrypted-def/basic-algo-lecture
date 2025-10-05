// Authored by : uhwan0723
// Co-authored by : -
// http://boj.kr/2104709e50904a80a64a245ab602968e
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int mn = 3005;
int n, par[mn], sz[mn];
vector<tuple<int, int, int, int>> lines;

int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3){
  int res = p1.X * p2.Y + p2.X * p3.Y + p3.X * p1.Y;
  res -= p1.Y * p2.X + p2.Y * p3.X + p3.Y * p1.X;
  if(res > 0) return 1;
  else if(res < 0) return -1;
  return 0;
}

bool isintersect(tuple<int, int, int, int> l1, tuple<int, int, int, int> l2){
  int l1x1, l1y1, l1x2, l1y2;
  tie(l1x1, l1y1, l1x2, l1y2) = l1;
    
  int l2x1, l2y1, l2x2, l2y2;
  tie(l2x1, l2y1, l2x2, l2y2) = l2;
  
  pair<int, int> p1 = {l1x1, l1y1}, p2 = {l1x2, l1y2};
  pair<int, int> p3 = {l2x1, l2y1}, p4 = {l2x2, l2y2};
  
  int f1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
  int f2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

  if(f1 == 0 && f2 == 0){
    if(p1 > p2) swap(p1, p2);
    if(p3 > p4) swap(p3, p4);
    return p1 <= p4 && p3 <= p2;
  }
  return f1 <= 0 && f2 <= 0;
}

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
  fill(par, par+n+5, -1);
  fill(sz, sz+n+5, 1);
  for(int i = 0; i < n; ++i){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    lines.push_back({x1, y1, x2, y2});
  }
    
  for(int i = 0; i < n; ++i)
    for(int j = i+1; j < n; ++j)
      if(isintersect(lines[i], lines[j])) uni(i, j);
  
  int cnt = 0;
  for(int i = 0; i < n; ++i)
    cnt += par[i] < 0;
  cout << cnt << '\n' << *max_element(sz, sz+n);
}

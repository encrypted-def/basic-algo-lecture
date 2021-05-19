// Authored by : Hot6Mania
// Co-authored by : -
// http://boj.kr/659c5fb01df043f6997a1aabc8a36f1b
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n, m;
int a[505][505], d[505][505];

int func(int x, int y){
  if(d[x][y] != -1) return d[x][y];
  if(x == n - 1 && y == m - 1) return 1;
  int &ret = d[x][y];
  ret = 0;
  for(int dir = 0; dir < 4; ++dir){
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    if(a[x][y] > a[nx][ny]) ret += func(nx, ny);
  }
  return ret;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
      cin >> a[i][j], d[i][j] = -1;
  cout << func(0, 0);
}

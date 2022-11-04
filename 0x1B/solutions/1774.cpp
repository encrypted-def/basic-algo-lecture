// Authored by : scsc3204
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/0025fc1eaf484e7cb9924f4693a56586
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;

int n, m;
int p[1002]; // an array to check parent nodes
pair<int, int> coord[1002]; // 1-indexed
vector< tuple<ll, int, int> > e;

int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool merge(int a, int b) {
  a = find(a); b = find(b);
  if(a == b) return 0;
  if(p[a] == p[b]) p[a]--;
  if(p[a] < p[b]) p[b] = a;
  else p[a] = b;
  return 1;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  fill(p, p + n + 1, -1);
  
  int x, y;
  for(int i = 1; i <= n; i++) {
    cin >> x >> y;
    coord[i] = {x, y};
  }
  int cnt = 0;
  for(int i = 0; i < m; i++) {
    cin >> x >> y;
    if(merge(x, y)) // 이미 연결된 두명을 묶음
      cnt++; // 이전에 묶여있지 않았을 경우 cnt 1 증가
  }

  ll len;
  for(int i = 1; i <= n; i++) {
    for(int j = i + 1; j <= n; j++) {
      int dx = (coord[i].X - coord[j].X);
      int dy = (coord[i].Y - coord[j].Y);
      len = ((ll)dx) * dx + ((ll)dy) * dy;
      e.push_back({len, i, j});
    }
  }

  sort(e.begin(), e.end());

  double ans = 0;
  for(auto cur : e) {
    tie(len, x, y) = cur;
    if(!merge(x, y)) continue;
    ans += sqrt(len);
    cnt++;
    if(cnt == n - 1) break;
  }
  cout << fixed;
  cout.precision(2);
  cout << ans;
}

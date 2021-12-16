// Authored by : std-freejia
// Co-authored by : -
// http://boj.kr/22b6f7fbfeee470a821f0aeca6427f08
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, a, b;
vector<pair<int, int>> v;

bool cmpx(pair<int,int> a, pair<int,int> b){
  return (a.X < b.X) ? 1:0;
}
bool cmpy(pair<int,int> a, pair<int,int> b) {
  return (a.Y < b.Y) ? 1:0;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a >> b; v.push_back({a, b});
  }
  stable_sort(v.begin(), v.end(), cmpx);  // x좌표가 증가하는 순
  stable_sort(v.begin(), v.end(), cmpy); // y좌표가 증가하는 순
  for(int i = 0; i < n; i++) cout << v[i].X << ' ' << v[i].Y << '\n';
  return 0;
}
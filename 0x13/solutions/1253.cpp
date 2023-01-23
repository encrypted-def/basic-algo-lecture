// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/cf7ce676aad54a2786941423afd99612
#include <bits/stdc++.h>
using namespace std;

int cnt, n;
vector<int> a;

void solve(int i) {
  for(int j = 0; j < n; j++) {
    if(j == i) continue;
    int x = a[i] - a[j];
    int idx = lower_bound(a.begin(), a.end(), x) - a.begin();
    while(idx < n && a[idx] == x) {
      if(idx != i && idx != j) { cnt++; return; }
      idx++;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    a.push_back(x);
  }

  sort(a.begin(), a.end());

  for(int i = 0; i < n; i++) solve(i);
  cout << cnt;
}
// Authored by : Hot6Mania
// Co-authored by : -
// http://boj.kr/4e72393705f74a3fa01ba3ac26dbba1f

#include <bits/stdc++.h>
using namespace std;

int n;
int a[1010], d[1010], pre[1010];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  fill(d, d+n, 1);
  
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j < i; ++j){
      if(a[j] < a[i] && d[i] < d[j] + 1){
        d[i] = d[j] + 1;
        pre[i] = j;
      }
    }
  }
  int maxi = 1, maxd = d[1];
  for(int i = 2; i <= n; ++i){
    if(maxd < d[i]){
      maxi = i;
      maxd = d[i];
    }
  }
  deque<int> ans;
  int cur = maxi;
  while(cur){
    ans.push_front(a[cur]);
    cur = pre[cur];
  }
  cout << ans.size() << '\n';
  for(auto x : ans) cout << x << ' ';
}

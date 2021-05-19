// Authored by : Hot6Mania
// Co-authored by : -
// http://boj.kr/e27e5b8dfc314c618c8975a2452026aa
#include <bits/stdc++.h>
using namespace std;

int n;
int t[20], p[20], d[20];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for(int i = 0; i < n; ++i) cin >> t[i] >> p[i];
  
  for(int i = 0; i < n; ++i){
    d[i] = max(d[i], d[i-1]);
    if(i + t[i] <= n + 1)
      d[i + t[i]] = max(d[i + t[i]], d[i] + p[i]);
  }
  
  cout << *max_element(d, d + n + 1);
}

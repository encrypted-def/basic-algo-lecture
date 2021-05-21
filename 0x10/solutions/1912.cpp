// Authored by : Hot6Mania
// Co-authored by : -
// http://boj.kr/a9a359faddb34f0faf591d3421b0e6af
#include <bits/stdc++.h>
using namespace std;

int n;
int a[100010], d[100010];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
    d[i] = a[i];
  }
  for(int i = 1; i <= n; ++i)
    d[i] = max(d[i], d[i-1] + a[i]);
  cout << *max_element(d + 1, d + n + 1);
}

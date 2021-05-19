// Authored by : Hot6Mania
// Co-authored by : -
// http://boj.kr/56aaa902f66645c58a86798d210d1dd1
#include <bits/stdc++.h>
using namespace std;

int n;
int d[100010];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for(int i = 1; i <= n; ++i){
    d[i] = i;
    for(int j = 1; j * j <= i; ++j)
      d[i] = min(d[i], d[i - j * j] + 1);
  }
  cout << d[n];
}

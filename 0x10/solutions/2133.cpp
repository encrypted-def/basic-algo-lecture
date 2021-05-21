// Authored by : Hot6Mania
// Co-authored by : -
// http://boj.kr/221ce74cdbde4516af72bc435b3de8bd
#include <bits/stdc++.h>
using namespace std;

int n;
int d[35];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  d[0] = 1; d[2] = 3;
  for(int i = 3; i <= n; ++i){
    d[i] += d[i-2] * 3;
    for(int j = i - 4; j >= 0; j -= 2){
      d[i] += d[j] * 2;
    }
  }
  cout << d[n];
}

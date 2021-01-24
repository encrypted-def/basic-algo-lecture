// http://boj.kr/ffe255761ed34ed4972855b85cb958af
#include <bits/stdc++.h>
using namespace std;

int s[305];
int n;
int d[305][2];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> s[i];
  if(n==1){
    cout << s[0];
    return 0;
  }
  d[0][0] = s[0];
  d[0][1] = 0;
  d[1][0] = s[1];
  d[1][1] = s[0]+s[1];
  for(int i = 2; i < n; i++){
    d[i][0] = max(d[i-2][0],d[i-2][1])+s[i];
    d[i][1] = d[i-1][0]+s[i];
  }
  cout << max(d[n-1][0],d[n-1][1]);
}

// http://boj.kr/e93e56bb850a46378cf8f53486233cdc
#include <bits/stdc++.h>
using namespace std;

int s[305];
int n;
int d[305];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int tot = 0;
  for(int i = 1; i <= n; i++){
    cin >> s[i];
    tot += s[i];
  }
  if(n <= 2){
    cout << tot;
    return 0;
  }
  d[1] = s[1];
  d[2] = s[2];
  d[3] = s[3];
  for(int i = 4; i <= n-1; i++) d[i] = min(d[i-2],d[i-3])+s[i];
  cout << tot - min(d[n-1],d[n-2]);
}

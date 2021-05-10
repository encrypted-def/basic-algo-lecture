// http://boj.kr/ed4da1d53a504c21805253b185513a9a
#include <bits/stdc++.h>
using namespace std;

bool isprime(int n){
  if(n == 1) return 0;
  for(int i = 2; i*i <= n; i++){
    if(n % i == 0) return 0;
  }
  return 1;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int cnt = 0;
  while(n--){
    int x;
    cin >> x;
    cnt += isprime(x);
  }
  cout << cnt << '\n';
}

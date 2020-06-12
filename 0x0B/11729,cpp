// http://boj.kr/f2440915dca04aaa9aec759080516973
#include <bits/stdc++.h>
using namespace std;

void func(int a, int b, int n){
  if(n == 1){
    cout << a << ' ' << b << '\n';
    return;
  }
  func(a, 6-a-b, n-1);
  cout << a << ' ' << b << '\n';
  func(6-a-b, b, n-1);
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k;
  cin >> k;
  cout << (1<<k) - 1 << '\n';
  func(1, 3, k);
}

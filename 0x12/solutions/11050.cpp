// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/88189dab63974f8e9446dd9d960aea56
#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k;
  cin >> n >> k;
  int ret = 1;
  for(int i = 1; i <= n; i++) ret *= i;
  for(int i = 1; i <= k; i++) ret /= i;
  for(int i = 1; i <= n-k; i++) ret /= i;
  cout << ret;
}

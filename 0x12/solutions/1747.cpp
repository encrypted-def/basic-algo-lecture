// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/f6dfaf2735934031bd0981961156ab72
#include <bits/stdc++.h>
using namespace std;

bool isprime(int n){
  if(n == 1) return 0;
  for(int i = 2; i*i <= n; i++){
    if(n % i == 0) return 0;
  }
  return 1;
}

bool ispalindrome(int n){
  int tmp = n;
  int n_rev = 0; // n_rev에는 n을 뒤집은 값이 저장됨
  while (n > 0) {
    n_rev = 10 * n_rev + n % 10;
    n /= 10;
  }
  return tmp == n_rev;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  while(!isprime(n) || !ispalindrome(n)) n++;
  cout << n;
}
/*
소수이면서 팰린드롬인 수가 나올 때 까지 탐색을 하면 된다.
1003001이 소수이면서 팰린드롬인 수이기 때문에 아무리 커봐야 1003001을
넘지 않는다.
*/

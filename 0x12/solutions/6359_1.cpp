// Authored by : haneulkimdev
// Co-authored by : -
// http://boj.kr/cbc162afb18b43c78c27a4b7e6ee3524
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << (int)sqrt(n) << '\n';
  }
}

/*
열리거나 닫히는 횟수는 그 수의 약수의 개수와 일치하는데,
열려있는 번호는 약수의 개수가 홀수 개다.
이는 제곱수의 특징인 약수가 홀수 개라는 것을 보여준다.
1부터 n까지의 자연수 중 제곱수의 개수는 ⌊n⌋개이다.
*/

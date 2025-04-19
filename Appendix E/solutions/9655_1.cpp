// Authored by : 0000000000
// Co-authored by : -
// http://boj.kr/97ae59164b45494fa916d3a4fe2511bc
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n; cin >> n;
  
  cout << (n % 2 ? "SK" : "CY");
}

/*
두 사람이 가져가는 돌의 수가 홀수개이기 때문에 n의 기우성에 따라 답이 정해진다.
*/

// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/8b763a1df15a4cb3936f7a181f3db97c
#include <bits/stdc++.h>
using namespace std;

// d[i] = i를 1, 2, 3의 합으로 나타내는 방법의 수
int d[20];
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  d[1] = 1; d[2] = 2; d[3] = 4;
  for(int i = 4; i < 11; i++)
    d[i] = d[i-1] + d[i-2] + d[i-3];

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    cout << d[n] << '\n';
  }
}

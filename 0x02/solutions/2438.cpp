// Authored by : wogha95
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/420d07c062f0404aa31c45d22ae01920
#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int N;
  cin >> N;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j <= i; j++)  cout << '*';
    cout << "\n";
  }
}

// Authored by : wogha95
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/b6adf7a5cfeb49f7a45563ac675a6b3a
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

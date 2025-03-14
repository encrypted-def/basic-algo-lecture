// Authored by : heheHwang
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/45e26df635a140df9354fb7d3fbf0497
#include <bits/stdc++.h>
using namespace std;

const int MXN = 10'002; 
vector<bool> sieve(MXN, 1);
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 2; i*i < MXN ; i++){
    if (!sieve[i]) continue;
    for (int j = i * i; j <= MXN; j += i) sieve[j] = false;
  } 

  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++) {
    int c;
    cin >> c;
    for (int a = c/2; 0 < a; a--){
      int b = c - a;
      if (sieve[a] && sieve[b]){
        cout << a << ' ' << b << '\n';
        break;
      }
    }  
  }
}

// Authored by : pha-ran (soft18)
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/c6e91442976c4a2a8e6c626462aceced
#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  long long a, b;
  cin >> a >> b;
  if (a > b) swap(a,b);
  if (a == b || b - a == 1) cout << 0;
  else {
    cout << b - a - 1 << "\n";
    for(long long i = a+1; i < b; i++)
      cout << i << " ";
  }
}

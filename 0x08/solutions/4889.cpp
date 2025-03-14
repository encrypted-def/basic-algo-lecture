// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/431d0c16ab78498898a51fe2334cdafb
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int ord = 0;
  while(true){
    ord++;
    string a;
    getline(cin, a);
    if(a[0]=='-')break;
    int cnt = 0;
    int ans = 0;
    for(auto c : a){
      if(c=='{') cnt++;
      else{
        cnt--;
        if(cnt == -1){
          cnt=1;
          ans++;
        }
      }
    }
    ans += cnt/2;
    cout << ord << ". " << ans << '\n';
  }  
}

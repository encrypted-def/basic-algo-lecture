// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/c8698bc57ac343dea8f836660aecc0b4
#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> v(n+m);
    for(int i = 0; i < n; i++){
      int a;
      cin >> a;
      v[i] = {a, 0};
    }
    for(int i = n; i < n+m; i++){
      int b;
      cin >> b;
      v[i] = {b, 1};
    }
    sort(v.begin(), v.end());
    int cnt = 0; // 현재까지 나온 b의 개수
    int ans = 0;
    for(int i = 0; i < n+m; i++){
      if(v[i].second == 0) // 현재 보는 수가 A에 속한 수
        ans += cnt;
      else // 현재 보는 수가 B에 속한 수
        cnt++;
    }
    cout << ans << '\n';
  }
}

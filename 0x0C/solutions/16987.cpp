// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/550e5f94d9504613971281134eebaeae
#include <bits/stdc++.h>
using namespace std;
int n;
int s[10],w[10];
int mx = 0;
int cnt = 0; // 깨져있는 계란의 수

void solve(int a){ // a번째 계란으로 다른걸 깰 차례
  if(a == n){
    mx = max(mx,cnt);
    return;
  }
  if(s[a] <= 0 or cnt == n-1){
    solve(a+1);
    return;
  } // a번째 계란이 깨져있거나 다른 모든 계란이 깨져있으면 넘어감
  for(int t = 0; t < n; t++){ // t번째 계란을 내려치고 싶다
    if(t == a or s[t] <= 0) continue;
    s[a] -= w[t];
    s[t] -= w[a];
    if(s[a] <= 0) cnt++;
    if(s[t] <= 0) cnt++;
    solve(a+1);
    if(s[a] <= 0) cnt--;
    if(s[t] <= 0) cnt--;    
    s[a] += w[t];
    s[t] += w[a];
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> s[i] >> w[i];
  }
  solve(0);
  cout << mx;  
}

// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/16d83e7cd636499ba665703eb00ea213
#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  priority_queue<int, vector<int>, greater<int>> pq;
  int n;
  cin >> n;
  while(n--){
    int x;
    cin >> x;
    pq.push(x);
  }
  int ans = 0;
  while(pq.size() > 1){
    int a = pq.top(); pq.pop();
    int b = pq.top(); pq.pop();
    ans += a + b;
    pq.push(a+b);
  }
  cout << ans;
}

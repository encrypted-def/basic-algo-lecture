// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/4954bb1881b64aed9f6d7b212a5e89a3
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[100005];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  int ans1 = 1e9+1;
  int ans2 = 1e9+1;
  for(int i = 0; i < n; i++){ // -a[i]에 대한 lower_bound를 구할 예정
    int idx = lower_bound(a, a+n, -a[i]) - a; // lower_bound의 성질에 따라 a[idx]는 -a[i]와 같거나, -a[i]보다 큰 원소 중에 가장 작은 원소이다.
    // a[i]와 더했을 때 값이 가장 작은 원소는 a[idx+1] 혹은 a[idx] 혹은 a[idx-1]이다.
    if(idx+1 < n && i != idx+1 && abs(a[i] + a[idx+1]) < abs(ans1 + ans2)){
      ans1 = a[i];
      ans2 = a[idx+1];
    }
    if(idx < n && i != idx && abs(a[i] + a[idx]) < abs(ans1 + ans2)){
      ans1 = a[i];
      ans2 = a[idx];
    }
    if(idx != 0 && i != idx-1 && abs(a[i] + a[idx-1]) < abs(ans1 + ans2)){
      ans1 = a[i];
      ans2 = a[idx-1];
    }
  }
  if(ans1 > ans2) swap(ans1, ans2); // 출력 형식에 맞게 설정
  cout << ans1 << ' ' << ans2;
}

/*
만약 같은 용액을 두 번 사용하는게 허용된다면 a[idx+1]은 고려하지 않아도 된다. 그러나 이 문제에서는 같은 용액을 두 번 사용할 수 없다는 조건이 있어서 a[i]와 더했을 때 값이 가장 작은 원소가 a[idx+1]일 수 있다.

예시 -> 수열 -100 1 10 14에서 i = 1일 때 idx = 1이고, a[1] + a[idx+1]이 가장 작다.
*/

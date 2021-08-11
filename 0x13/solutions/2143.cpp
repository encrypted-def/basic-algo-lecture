// Authored by : qhsl1213
// Co-authored by : -
// http://boj.kr/2b3bddae4e384ecb94bcd3437f3514ba
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll arr1[1001], arr2[1001];
ll dp1[1001], dp2[1001];
vector<ll> vec1, vec2;
ll cnt;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T, N, M;
  cin >> T;

  /* 배열 A, B 각각의 모든 부배열의 합을 dp로 구합니다. 이러한 테크닉은 BOJ 11659번 구간 합 구하기 4 문제의 풀이와 동일합니다. */

  // 1. dp[i]에 배열의 0~i번째 값의 합을 저장해놓습니다.
  cin >> N;
  for(int i=1; i<=N; i++) {
    cin >> arr1[i];
    dp1[i] = dp1[i-1] + arr1[i];
  }
  cin >> M;
  for(int i=1; i<=M; i++) {
    cin >> arr2[i];
    dp2[i] = dp2[i-1] + arr2[i];
  }

  // 2. dp[i]-dp[j]를 통해 배열 A, B 각각의 모든 부배열의 합을 구할 수 있습니다.
  for(int i=1; i<=N; i++){
    for(int j=0; j<i; j++){
      vec1.push_back(dp1[i]-dp1[j]);
    }
  }
  for(int i=1; i<=M; i++){
    for(int j=0; j<i; j++){
      vec2.push_back(dp2[i]-dp2[j]);
    }
  }

  /* 배열 A의 모든 부배열의 합 각각에 대해, 그것이 배열 B의 어떤 부배열의 합과 더하여 T를 만들 수 있는 지를 확인하여 카운팅하면 됩니다. */
  sort(vec1.begin(), vec1.end());
  sort(vec2.begin(), vec2.end());
  for(int i=0; i<vec1.size(); i++){
    int need = T - vec1[i]; // 배열 B의 모든 부배열의 합 중 그 값이 need인 것의 개수를 구하여 더합니다.
    cnt += upper_bound(vec2.begin(), vec2.end(), need) - lower_bound(vec2.begin(), vec2.end(), need);
  }
  cout << cnt;
}
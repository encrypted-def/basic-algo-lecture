// Authored by : qhsl1213
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/2daca686c11041b190d57441bd7f5467
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sol[5000];
ll ans[3] = {0x7f7f7f7f7f7f, 0x7f7f7f7f7f7f, 0x7f7f7f7f7f7f};
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  for(int i = 0; i < N; i++)
    cin >> sol[i];
  sort(sol, sol+N);

  // 두 용액을 섞은 결과에 하나의 용액을 더 섞어서 0으로 만드는 가장 가까운 용액 찾기
  for(int i = 0; i < N; i++){
    for(int j = i+1; j < N; j++){
      int idx = lower_bound(sol, sol+N, -sol[i] - sol[j]) - sol;

      // idx-2, idx-1, idx, idx+1, idx+2 위치에 있는 용액이 최적일 수 있다.
      for(int k = -2; k <= 2; k++){
        if(idx+k == i || idx+k == j) continue;
        if(idx+k < 0 || idx+k >= N) continue;
        if(abs(ans[0] + ans[1] + ans[2]) > abs(sol[i] + sol[j] + sol[idx+k]))
          tie(ans[0], ans[1], ans[2]) = {sol[i], sol[j], sol[idx+k]}; // tie를 이용해 값 3개를 한번에 assign.        
      }
    }
  }
  sort(ans, ans+3); // 출력 형식 맞추기.
  cout << ans[0] << " " << ans[1] << " " << ans[2];
}

/*
세 개의 "서로 다른 용액"을 혼합해야 한다는 점에 주의해야 한다.
"idx-2, idx-1, idx, idx+1, idx+2 위치에 있는 용액이 최적일 수 있다."는 주석에 설명을 추가하면,

-10 -7 -5 -2 1 1000 1001 1002

과 같은 예제를 생각해보자. 여기서 i = 3, j = 4인 경우 sol[3] = -2, sol[4] = 1에 대해서
abs(sol[3] + sol[4] + sol[k])가 최소인 k를 찾고자 한다. (단 k != i, k != j. 이 경우 k = 2이다.)

21번째줄의 idx는 계산을 해보면 4가 되는데, 서로 다른 용액을 혼합해야 한다는 조건으로 인해
최대 idx-2까지 탐색을 해야 주어진 i, j에 대한 올바른 k를 구할 수 있다.

idx+2까지 탐색을 해야하는 예제도 아래와 같이 쉽게 구성할 수 있다.(i = 1, j = 2일 때)

-500 -1 2 10 1001 1002

만약 "idx-1, idx, idx+1" 위치에 있는 용액에 대해서 확인을 한다면 어떤 i, j에 대해서는
올바른 k를 구하지 못할 수 있다. 다만 사실 "idx-1, idx, idx+1"으로 범위를 놓고 코드를
구성해도 사실 통과가 가능하다. 답이 sol[a], sol[b], sol[c]이라고 하면 i = a, j = b 혹은
i = b, j = c일 때 "idx-1, idx, idx+1" 위치만 확인할 경우 k를 잘못 구할 수 있지만,
적어도 i = a, j = c일 때에는 k = b를 잘 찾을 수 있기 때문이다.

그러나 이 내용을 관찰하지 못할 수 있으니 그냥 idx-2부터 idx+2까지 확인하도록 코드를 구성했다.
*/

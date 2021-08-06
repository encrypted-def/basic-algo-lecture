// Authored by : qhsl1213
// Co-authored by : -
// http://boj.kr/3a8765e1287540c9b9ed5d2bf9964879
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sol[5000];
vector<pair<int, int>> two;
ll answer[3];
ll zz = 1e10;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  for(int i=0; i<N; i++)
    cin >> sol[i];
  sort(sol, sol+N);

  // 모든 두 용액 조합 생성하기.
  for(int i=0; i<N-1; i++){
    for(int j=i+1; j<N; j++) {
      two.push_back({i, j});
    }
  }

  // 두 용액을 섞은 결과에 하나의 용액을 더 섞어서 0으로 만드는 가장 가까운 용액 찾기
  for(int i=0; i<two.size(); i++){
    int f_idx = two[i].first, s_idx = two[i].second;
    ll first = sol[f_idx], second = sol[s_idx];
    int idx = lower_bound(sol, sol+N, -(first+second)) - sol;

    // idx-1, idx, idx+1 위치에 있는 용액이 최적일 수 있다.
    for(int j=-1; j<=1; j++){
      if(idx+j != f_idx && idx+j != s_idx && idx+j >= 0 && idx+j < N){
        if(abs(zz) > abs(first+second+sol[idx+j])){
          zz = first+second+sol[idx+j];
          answer[0] = first; answer[1] = second; answer[2] = sol[idx+j];
        }
      }
    }

  }
  sort(answer, answer+3); // 출력 형식 맞추기.
  cout << answer[0] << " " << answer[1] << " " << answer[2];
}
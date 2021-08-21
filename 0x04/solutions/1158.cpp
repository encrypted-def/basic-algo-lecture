// Authored by : OceanShape
// Co-authored by : -
// http://boj.kr/dd87efb95a074162933e66209b9a0c60
#include <bits/stdc++.h>
using namespace std;

int N, K;
queue<int> q;
vector<int> v;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;

  // N명의 사람을 순서대로 큐에 저장
  for(int i = 1; i <= N; ++i) q.push(i);

  // N명의 사람이 모두 제거될 때까지 진행
  while(!q.empty()){
    for(int i = 1; i <= K; ++i) {
      int tmp = q.front();
      q.pop();
      // K 번째 사람을 만날 경우, 순열에 저장
      if(i == K) {
        v.push_back(tmp);
      }
      // K 번째 사람이 아닐 경우, 다시 큐에 저장
      else {
        q.push(tmp);
      }
    }
  }

  // 순열 출력
  cout << '<';
  for(size_t i = 0; i < v.size(); ++i) {
    cout << v[i];
    if (i != v.size() - 1) cout << ", ";
  }
  cout << '>';
}

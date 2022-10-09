// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/204f4beaeebe49c9ad5a7530640ca7fe
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, dl, cn;
  unsigned int cupNoodles = 0;
  priority_queue<unsigned int> cn_candidate;
  vector<vector<unsigned int>> cn_by_deadline(200'002);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> dl >> cn;
    cn_by_deadline[dl].push_back(cn);
  }
  for (int curr = 200'001; curr != 0; curr--) {
    for (int noodle : cn_by_deadline[curr])
      cn_candidate.push(noodle);

    if (cn_candidate.empty()) continue;
    cupNoodles += cn_candidate.top();
    cn_candidate.pop();
  }
  cout << cupNoodles;
}
/*
해당 문제는 특정 데드라인에 여러 문제가 걸릴 수 있다는 점을 주의해야 합니다.
가령 데드라인이 닥쳐오는데로 컵라면이 많이 걸린 문제를 집었다가는,
데드라인은 나중이지만 컵라면을 많이 주는 여러 문제들을 놓칠 수 있습니다.
구체적인 예를 들자면,
3
1 1
2 10
2 20
위 예시는 1+20=21이 아니라 10+20=30개의 컵라면을 얻는 것이 최적입니다.
따라서 거꾸로 계산한 시간을 기준으로 데드라인 안쪽에 해당하는
문제들을 모은 후, 가장 컵라면을 많이 주는 문제부터 골라야 합니다.
*/
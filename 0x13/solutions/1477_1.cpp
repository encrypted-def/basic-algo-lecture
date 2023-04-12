// Authored by : syoh0708
// Co-authored by : -
// http://boj.kr/05fce9b513ae4712bc82a0f5324e8727
#include <bits/stdc++.h>

using namespace std;

int a[52];

class Cmp {
public:
  bool operator() (pair<int, int> a, pair<int, int> b) {
    return a.first * (b.second + 1) < b.first * (a.second + 1);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> q;
  int n, m, l; cin >> n >> m >> l;

  for (int i = 0; i < n; i++) cin >> a[i + 1];

  a[0] = 0;
  a[n + 1] = l;

  sort(a, a + n + 2);

  for (int i = 0; i <= n; i++) q.push({a[i + 1] -  a[i], 0});
  for (int i = 0; i < m; i++) {
    pair<int, int> cur = q.top(); q.pop();
    q.push({cur.first, cur.second + 1});
  }

  pair<int, int> max_dist = q.top();
  cout << (max_dist.first - 1) / (max_dist.second + 1) + 1;
}

/**
 * 처음에 세워진 휴게소로 나눠진 i 번쨰 구간의 길이를 a_i
 * i 번째 구간에 세워진 휴게소의 개수를 b_i 개라고 하면
 * i 번째 구간의 휴게소가 없는 구간의 최대값의 최소값은 (a_i - 1) / (b_i + 1) + 1이 된다.
 * 우리는 처음에 세워진 휴게소로 나눠진 N+1개의 구간들에 대해 M개의 휴게소를 "적절히" 넣으려고 하는데,
 * "적절히" 넣는다는 의미는 매 순간마다 N+1개의 구간 중 휴게소가 없는 구간의 길이가 
 * 가장 긴 (= (a_i - 1) / (b_i + 1) + 1이 최대인) 곳에 휴게소를 배치하는 방법이다.
 * (a_i에 1을 빼주고 나눈 다음에 더해주는 이유는 나누어 떨어지지 않는 경우 처리해주기 위함)
 * priority_queue q의 첫 번째 원소 pair<int, int> max_dist에 대해서
 * (max_dist.first - 1) / (max_dist.second + 1) + 1 는 
 * 언제나 휴게소가 없는 구간의 최댓값의 최솟값이 된다.
 */

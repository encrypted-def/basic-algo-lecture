// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/3597912a5c77487e8a81bb93ae471450
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int MX = 100'000;

int p[MX + 2]; 
pair<int, int> x[MX + 2];
pair<int, int> y[MX + 2];
pair<int, int> z[MX + 2];

vector<tuple<int, int, int>> e; // e = {cost, u, v};

int find(int cur) {
  if(p[cur] < 0) return cur;
  return p[cur] = find(p[cur]);
}

bool is_diff_group(int u, int v) {
  u = find(u); v = find(v);
  if(u == v) return 0;
  if(p[u] > p[v]) swap(u, v);
  p[u] += p[v];
  p[v] = u;
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(p, p + MX + 2, -1);
  int n; cin >> n;
  for(int i = 0; i < n; i++) {
    int cx, cy, cz;
    cin >> cx >> cy >> cz;
    x[i] = {cx, i};
    y[i] = {cy, i};
    z[i] = {cz, i};
  }
  
  sort(x, x + n);
  sort(y, y + n);
  sort(z, z + n);

  for(int i = 1; i < n; i++) {
    e.push_back({abs(x[i - 1].X - x[i].X), x[i - 1].Y, x[i].Y});
    e.push_back({abs(y[i - 1].X - y[i].X), y[i - 1].Y, y[i].Y});
    e.push_back({abs(z[i - 1].X - z[i].X), z[i - 1].Y, z[i].Y});
  }
  
  sort(e.begin(), e.end());

  int cnt = 0, sum = 0;
  for(auto [cost, u, v] : e) {
    if(!is_diff_group(u, v)) continue;
    sum += cost;
    cnt++;
    if(cnt == n - 1) break;
  }
  cout << sum;
}
/*
모든 행성 간 간선을 계산하고 저장하면
최악의 경우 약 50억 개의 간선 정보를 저장해야 합니다.
따라서 꼭 필요한 간선 정보만 추려낼 논리가 필요합니다.

직관적으로 생각하면 새로운 행성을 MST에 추가할 때 굳이 가까운 행성 대신 더 멀리
있는 행성을 택할 이유는 없어보입니다. 그렇기 때문에 x, y, z축 각각에 대해
앞뒤에 인접한 행성에 대해서만 간선이 있다고 생각할 수 있습니다.

i번째 행성의 좌표 정보를 받아
pair<int, int> x, y, z 배열에 저장합니다.
이 배열은 좌표 값과 행성 번호를 기록합니다.

이 좌표 배열들을 정렬하면(47-49번째 줄)
좌표의 차이가 적은 좌표 값들을 앞뒤 인덱스에 둘 수 있습니다.
이를 활용해 좌표 값 간의 차이를 절대값으로 계산해 간선의 비용을 계산하고,
간선이 잇는 두 행성의 번호를 간선 정보로 함께 저장합니다(51-55번째 줄).

이후 크루스칼 알고리즘을 따라
간선 정보를 비용에 대해 오름차순으로 정렬하고,
비용이 작은 간선부터 확인하며 MST를 구축합니다.
이 과정에서 간선 가중치 총합의 최솟값을 계산하고 그 값을 답으로 출력합니다.
*/

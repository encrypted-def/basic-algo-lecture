// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/33d72cefdf7847cbb5f2a6dab88b21da
#include <bits/stdc++.h>
using namespace std;

const int MX = 100;

unordered_map<string, int> city_to_id;
int citycnt = 0;

vector<int> dest; // destination
int d[2][MX + 2][MX + 2]; // d[is_railro][u][v] = (cost for u to v)

int trans_code(string &str) {
  if(str[0] == 'S' && str[1] == '-') return 1; // S-train: 50% 할인
  else if(str[0] == 'V') return 1; // V-train: 50% 할인
  else if(str[0] == 'I' || str[0] == 'M') return 2; // ITX, 무궁화: 공짜
  return 0; // 가격 변동 없음
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, diff;
  cin >> n >> diff;
  diff *= 2;
  for(int i = 0; i < n; i++) {
    string name; cin >> name;
    auto it = city_to_id.find(name);
    if(it == city_to_id.end()) 
      city_to_id[name] = citycnt++;
  }

  cin >> n;
  for(int i = 0; i < n; i++) {
    string name; cin >> name;
    dest.push_back(city_to_id[name]);
  }

  memset(d, 0x3f, sizeof(d));
  for(int i = 0; i < citycnt; i++) {
    d[0][i][i] = 0;
    d[1][i][i] = 0;
  }

  cin >> n;
  for(int i = 0; i < n; i++) {
    string tr, uname, vname; int cost;
    cin >> tr >> uname >> vname >> cost;
    cost *= 2;
    int u = city_to_id[uname];
    int v = city_to_id[vname];

    cost = min(d[0][u][v], cost);
    d[0][u][v] = d[0][v][u] = cost;

    int trcode = trans_code(tr);
    if(trcode == 1) cost /= 2;
    else if(trcode == 2) cost = 0;

    cost = min(d[1][u][v], cost);
    d[1][u][v] = d[1][v][u] = cost;
  }

  for(int k = 0; k < citycnt; k++)
    for(int i = 0; i < citycnt; i++)
      for(int j = 0; j < citycnt; j++)
        for(int m = 0; m < 2; m++)
          d[m][i][j] = min(d[m][i][j], d[m][i][k] + d[m][k][j]);

  for(int i = 1; i < dest.size(); i++) {
    int u = dest[i - 1];
    int v = dest[i];
    diff -= d[0][u][v];
    diff += d[1][u][v];
  }

  if(diff < 0) cout << "Yes";
  else cout << "No";
}
/*
도시 이름으로 도시 고유 번호를 불러올 수 있도록 해시를 활용합니다.
목적지는 해시를 통해 도시 고유 번호를 불러와 해당 번호를 저장합니다.

인접행렬 2개를 사용해서 내일로 사지 않은 경우와 산 경우를 구분해 비용을 입력 받습니다.
인접행렬에 기록된 값과 현재 입력된 값 중 최솟값을 비용으로 저장합니다.
내일로를 구매한 경우, 문제 조건에 따라 할인된 금액을 저장합니다.
정수 범위로 정확히 값을 산정하기 위해 모든 비용은 2배를 큰 값으로 둡니다.

인접행렬의 모든 값을 0x3f3f3f3f로 초기화합니다.
그 후 `i == j`인 경우에만 0을 넣습니다(42-46번째 줄).

diff는 (내일로를 구매한 총 여행비용) - (내일로를 구매하지 않은 총 여행비용)을 의미합니다.
따라서, 경로를 돌면서 내일로를 구매하지 않은 이동 비용은 diff에서 차감하고,
내일로를 구매한 경우의 이동 비용은 diff에 더합니다.

이렇게 계산된 diff는 답을 출력할 때 활용됩니다.
- diff < 0인 경우 내일로를 사는 게 유리한 경우이기 때문에 Yes를 출력합니다.
- diff >= 0인 경우 내일로를 사는 게 이득이 없거나 불리한 경우이기 때문에 No를 출력합니다.
*/
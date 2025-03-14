// Authored by : jimi567
// Co-authored by : -
// http://boj.kr/7d30341579424e59a3868fc91e1980d6
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
int n, m;
int arr[1005][1005];
int ans = 0x7f7f7f7f;
vector<int> idx;  //각 팀들의 현재 인덱스를 저장하는 벡터.
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    idx.push_back(0);
    for (int j = 0; j < m; j++) cin >> arr[i][j];
  }
  for (int i = 0; i < n; i++) sort(arr[i], arr[i] + m);
  while (1) {
    int mntm;
    int mx = -1;
    int mn = 0x7f7f7f7f;
    for (int i = 0; i < n; i++) {
      if (mn > arr[i][idx[i]]) {  //최솟값 갱신, 최솟값을 가지는 팀 갱신
        mn = arr[i][idx[i]];
        mntm = i;
      }
      if (mx < arr[i][idx[i]]) mx = arr[i][idx[i]];  //최댓값 갱신
    }
    ans = min(ans, mx - mn);
    idx[mntm] += 1;
    if (idx[mntm] == m)
      break;  //만약 최솟값을 가지는 팀이 마지막 인덱스에 해당하면 종료.
  }
  cout << ans;
}

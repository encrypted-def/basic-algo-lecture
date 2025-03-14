// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/1565201145304e9e81bdc7ee4be56948
#include <bits/stdc++.h>
using namespace std;

int n, m;
int d[50][4];
string a = "ACGT";

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while(n--) {
    string s; cin >> s;
    for(int i = 0; i < m; i++) {
      int j = a.find(s[i]);
      d[i][j]++;
    }
  }

  int sum = 0;
  for(int i = 0; i < m; i++) {
    int mx = -1, idx = -1;
    for(int j = 0; j < 4; j++) {
      sum += d[i][j];
      if(mx >= d[i][j]) continue;
      mx = d[i][j];
      idx = j;
    }
    sum -= mx;
    cout << a[idx];
  }
  cout << '\n' << sum << '\n';
}
/*
가장 많이 출현한 뉴클레오티드를 해당 인덱스의 뉴클레오티드로 결정하면
Hamming Distance의 합을 최소화할 수 있습니다.
이때, 출현 빈도가 동일한 경우 알파뱃 순으로 앞서는 알파뱃을 출력합니다.

먼저, 뉴클레오티드의 첫글자를 알파벳 순으로 모아 문자열 a를 구성합니다.

2차원 배열 d는 DNA의 0번 인덱스 뉴클레오티드부터 m-1번 인덱스 뉴클레오티드까지
인덱스 별로 구분하여 각 뉴클레오티드의 출현 빈도를 기록합니다.
즉, d[i][j]는 i번 인덱스 뉴클레오티드가 a[j]인 DNA의 수입니다.
j = 0일 때 뉴클레오티드의 종류는 A이며, j = 1일 때 C, j = 2일 때 G, j = 3일 때 T입니다.
따라서 j는 a에 find 메소드를 적용해 구할 수 있습니다(19번째 줄).

이제 Hamming Distance의 총합을 sum에 기록하면서
Hamming Distance의 합이 가장 작은 DNA를 출력합니다.
25-35번째 줄을 따라서 mx값과 idx를 -1로 설정한 뒤,
출현 빈도 중 큰 값을 mx에 갱신하고,
이렇게 갱신됐을 때 idx도 함께 갱신합니다.
이를 통해 가장 많은 출현 빈도를 갖는 알파뱃 중
사전순으로 앞서는 것의 문자열 a 내 인덱스를 idx에 기록합니다.

여기서 알파뱃을 선택하면 해당 알파뱃을 뉴클레오티드로 갖는 DNA의 수는
Hamming Distance에 들어가지 않으므로, 지금까지 더한 sum에서 mx를 빼줍니다.

저장했던 idx는 a[idx]로 인덱싱해서 출력해줍니다.
이후 최소 Hamming Distance 값을 저장하고 있는 sum 값을 출력합니다.
*/
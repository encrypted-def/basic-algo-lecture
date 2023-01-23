// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/2300d12c7a24426a97284f983d31b3fa
#include <bits/stdc++.h>
using namespace std;

vector<bool> a(10, 0);

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int cnt = 0;

  int n; cin >> n;
  for(int i = 1; i <= 10; i++) {
    a[10 - i] = 1;
    do {
      if(cnt != n) {
        cnt++;
        continue;
      }
      for(int i = 0; i < 10; i++)
        if(a[i]) cout << 9 - i;
      return 0;
    } while(next_permutation(a.begin(), a.end()));
  }
  cout << -1;
}
/*
감소하는 수는 같은 숫자가 중복해서 쓰일 수 없다.
또한, 몇 개 숫자를 선택해서 줄 세우는, 즉 순열 중에
감소하는 순열은 유일하다.
이 두 가지 사실을 통해 조합을 통해 감소하는 수를 셀 수 있다.

next_permutation과 0, 1로 이루어진 벡터 a를 활용하여
감소하는 수를 만들고 cnt를 증가시킨다.

cnt가 n에 도달할 경우, 만들어진 조합을 출력한다.
크기 10인 벡터 a의 인덱스 0부터 9은 숫자 9부터 0에 대응된다.
a[i]가 1인 경우, 이는 숫자 9-i이다(24번째 줄 구현 시 활용).

만약 모든 감소하는 수를 만들고도 cnt가 n에 도달하지 못했다면 -1을 출력한다.

코드에서 수를 탐색하는 순서는 i가 증가함에 따라 1자리 수 -> 2자리 수 -> 3자리 수 -> ... 이고
각 자리의 수는 next_permutation을 통해 작은 것 부터 탐색을 하기 때문에
이 코드는 자연스럽게 감소하는 수를 순서대로 세어나간다.
*/

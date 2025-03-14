// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/a41bcccb4c724fbba5ed3bf54a418948
#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;

    int a, b;
    while(m--) cin >> a >> b;
    cout << (n-1) << '\n';
  }
}

/*
MST 문제라는 것을 파악했다면 (정점의 수)-1개의 간선이 필요하기 때문에
주어지는 입력을 받고 간선의 수를 출력하면 된다.
*/
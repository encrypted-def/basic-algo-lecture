// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/359583ea75ef49f7acf7c5564827ebba
#include <bits/stdc++.h>
using namespace std;

int a[9];
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 0; i < 9; i++) cin >> a[i];
  cout << *max_element(a, a+9) << '\n';
  cout << max_element(a, a+9) - a + 1;
}

/*
max_element 함수를 이용한 풀이
*/

// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/4c29334a05624e9b88fde38677834a97
#include <bits/stdc++.h>
using namespace std;

int num[21];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
    
  for(int i = 1; i <= 20; i++) num[i] = i;
    
  for(int i = 1; i <= 10; i++) {
    int a, b;
    cin >> a >> b;        
    reverse(num+a, num+b+1);
  }
    
  for(int i = 1; i <= 20; i++) cout << num[i] << ' ';
}

/*
STL reverse를 이용한 풀이
*/

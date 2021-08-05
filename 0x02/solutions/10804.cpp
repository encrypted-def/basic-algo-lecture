// Authored by : wogha95
// Co-authored by : -
// http://boj.kr/a4b9840bd6aa45d183f1b8ccc2b54e61
#include <bits/stdc++.h>
using namespace std;

int num[21];

// 카드를 역순으로 놓는 함수
void reverse(int a, int b){
  for(int i = 0; i < (b - a + 1) / 2; i++){
    int temp = num[a + i];
    num[a + i] = num[b - i];
    num[b - i] = temp;
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
    
  for(int i = 1; i <= 20; i++) num[i] = i;
    
  for(int i = 1; i <= 10; i++) {
    int a, b;
    cin >> a >> b;
        
    reverse(a, b);
  }
    
  for(int i = 1; i <= 20; i++) cout << num[i] << ' ';
}
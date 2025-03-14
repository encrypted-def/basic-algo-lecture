// http://boj.kr/eeee207545644480a1971a2723769d93
#include <bits/stdc++.h>
using namespace std;

int freq[2000001];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int a;
    cin >> a;
    freq[a+1000000]++;
  }
  for(int i = 0; i <= 2000000; i++){
    while(freq[i]--){ // cnt[i]번 반복
      cout << i-1000000 << '\n';
    }
  }
}

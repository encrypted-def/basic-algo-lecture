// http://boj.kr/8b88c60fcf17452a9e602ef1bc17adde
#include <bits/stdc++.h>
using namespace std;

int n, m;
long long state[10];

int bit_cnt(long long x){
  int ret = 0;
  for(int i = 0; i < max(n, m); i++){
    ret += (x >> i) & 1;
  }
  return ret;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    string name, tmp; // name은 사실 의미없음
    cin >> name >> tmp;
    for(int j = m-1; j >= 0; j--){
      state[i] = (state[i] << 1) | (tmp[j] == 'Y');
    }
  }

  pair<int, int> ans = {0, -1}; // {연주할 수 있는 곡의 수, 필요한 기타의 수}
  for(int tmp = 0; tmp < (1 << n); tmp++){
    long long comb = 0; // 조합한 결과
    for(int i = 0; i < n; i++){
      if((tmp & (1LL << i)) == 0)
        continue;
      comb |= state[i];
    }
    int song_num = bit_cnt(comb);
    int guitar_num = bit_cnt(tmp);
    if(ans.first < song_num) // 1. 연주할 수 있는 곡의 수가 더 많을 경우
      ans = {song_num, guitar_num};
    // 2. 연주할 수 있는 곡의 수는 같은데 필요한 기타의 수가 더 적을 경우
    else if(ans.first == song_num && ans.second > guitar_num)
      ans = {song_num, guitar_num};
  }
  cout << ans.second << '\n';
}

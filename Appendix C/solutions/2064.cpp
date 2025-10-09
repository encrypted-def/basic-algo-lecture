// Authored by : uhwan0723
// Co-authored by : -
http://boj.kr/7537647dfa6d4aeabf0599060c0c1c3f
#include <bits/stdc++.h>
using namespace std;

int n, bytes[4];
unsigned int mask, mx = 0, mn = 0xFFFFFFFF;

void print(unsigned int addr){
  for(int i = 0; i < 4; ++i)
    bytes[i] = (addr >> i*8) & ((1 << 8) - 1);
  printf("%d.%d.%d.%d\n", bytes[3], bytes[2], bytes[1], bytes[0]);
}

int main(void){
  scanf("%d", &n);
  while(n--){
    scanf("%d.%d.%d.%d", bytes+3, bytes+2, bytes+1, bytes);
    unsigned int ip = 0;
    for(int i = 0; i < 4; ++i)
      ip |= (bytes[i] << i*8);
    mx = max(mx, ip);
    mn = min(mn, ip);
  }
  mask = ~(mx ^ mn);
  for(int i = 31; i >= 0; --i){
    if(((mask >> i) & 1) == 1) continue;
    mask = (mask >> i) << i;
    break;
  }
  print(mx & mask);
  print(mask);
}

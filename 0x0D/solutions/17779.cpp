// Authored by : ximgea
// Co-authored by : -
// http://boj.kr/845430f915a640f5954bfe308a34b336
#include <bits/stdc++.h>
using namespace std;

int n;
array<array<int, 25>, 25> city;
array<array<int, 25>, 25> district;

void election_district(int x, int y, int d1, int d2) {

  district = {};
  //fill 5
  for(int i{1}; i<=n; ++i) {
    for(int j{1}; j<=n; ++j) {
      if(i+j < x+y) continue;
      if(i+j > x+y+2*d2) continue;
      if(j-i > -x+y) continue;
      if(j-i < -x+y-2*d1) continue;
      district[i][j] = 5;
    }
  }

  //fill the rest
  for(int i{1}; i<=n; ++i) {
    for(int j{1}; j<=n; ++j) {
      if(district[i][j] == 5) continue;
      else if((1 <= i && i < x+d1) && (1 <= j && j <= y))
        district[i][j] = 1;
      else if((1 <= i && i <= x+d2) && (y < j && j <= n))
        district[i][j] = 2;
      else if((x+d1 <= i && i <= n) && (1 <= j && j < y-d1+d2))
        district[i][j] = 3;
      else if((x+d2 < i && i <= n) && (y-d1+d2 <= j && j <= n))
        district[i][j] = 4;
    }
  }
}

int count() {
  array<int, 6> peoples = {};
  for(int i{1}; i<=n; ++i) {
    for(int j{1}; j<=n; ++j) {
      peoples[district[i][j]] += city[i][j];
    }
  }
  return *max_element(peoples.begin()+1, peoples.end()) - *min_element(peoples.begin()+1, peoples.end());
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i{1}; i<=n; ++i) {
    for(int j{1}; j<=n; ++j) {
      cin >> city[i][j];
    }
  }

  auto ans = 0x7fffffff;

  //set the point x, y
  for(int i{1}; i<=n; ++i) {
    for(int j{1}; j<=n; ++j) {
      //set the d1, d2
      for(int d1{1}; d1<=n; ++d1) {
        for(int d2{1}; d2<=n; ++d2) {
          if(!(i < i+d1+d2 && i+d1+d2 <= n)) continue;
          if(!(1 <= j-d1 && j-d1 < j && j < j+d2 && j+d2 <= n)) continue;
          election_district(i,j,d1,d2);
          ans = min(ans, count());
        }
      }
    }
  }
  cout << ans;
}

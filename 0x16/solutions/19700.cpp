// Authored by : reenact
// Co-authored by : -
// http://boj.kr/8b848a008bf14d309231e43620af8df9
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<pair<int, int>> arr;
  multiset<int> ms;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    int h, k;
    cin >> h >> k;
    arr.push_back({h, k});
  }
  sort(arr.begin(), arr.end(), compare);
  
  for (int i = 0; i < n; i++){
    if (ms.empty()) ms.insert(1);
    else{
      auto a = ms.lower_bound(arr[i].second);
      if (a == ms.begin()) ms.insert(1);
      else{
        int k = *prev(a) + 1;
        ms.erase(prev(a));
        ms.insert(k);
      }
    }
  }
  cout << ms.size();
  return 0;
}
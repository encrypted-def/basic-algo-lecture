#include <bits/stdc++.h>
using namespace std;

int main(void){
  deque<int> DQ;
  DQ.push_front(10); // 10
  DQ.push_back(50); // 10 50
  DQ.push_front(24); // 24 10 50
  for(auto x : DQ)cout<<x;
  cout << DQ.size() << '\n'; // 3
  if(DQ.empty()) cout << "DQ is empty\n";
  else cout << "DQ is not empty\n"; // DQ is not empty
  DQ.pop_front(); // 10 50
  DQ.pop_back(); // 10
  cout << DQ.back() << '\n'; // 10
  DQ.push_back(72); // 10 72
  cout << DQ.front() << '\n'; // 10
  DQ.push_back(12); // 10 72 12
  DQ[2] = 17; // 10 72 17
  DQ.insert(DQ.begin()+1, 33); // 10 33 72 17
  DQ.insert(DQ.begin()+4, 60); // 10 33 72 17 60
  for(auto x : DQ) cout << x << ' ';
  cout << '\n';
  DQ.erase(DQ.begin()+3); // 10 33 72 60
  cout << DQ[3] << '\n'; // 60
  DQ.clear(); // DQ의 모든 원소 제거
}

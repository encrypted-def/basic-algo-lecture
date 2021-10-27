#include <bits/stdc++.h>
using namespace std;

void unordered_set_example(){
  unordered_set<int> s;
  s.insert(-10); s.insert(100); s.insert(15); // {-10, 100, 15}
  s.insert(-10); // {-10, 100, 15}    
  cout << s.erase(100) << '\n'; // {-10, 15}, 1
  cout << s.erase(20) << '\n'; // {-10, 15}, 0
  if(s.find(15) != s.end()) cout << "15 in s\n";
  else cout << "15 not in s\n";
  cout << s.size() << '\n'; // 2
  cout << s.count(50) << '\n'; // 0
  for(auto e : s) cout << e << ' ';
  cout << '\n';
}

void unordered_multiset_example(){
  unordered_multiset<int> ms;
  ms.insert(-10); ms.insert(100); ms.insert(15); // {-10, 100, 15}
  ms.insert(-10); ms.insert(15);// {-10, -10, 100, 15, 15}
  cout << ms.size() << '\n'; // 5
  for(auto e : ms) cout << e << ' ';
  cout << '\n';
  cout << ms.erase(15) << '\n'; // {-10, -10, 100}, 2
  ms.erase(ms.find(-10)); // {-10, 100}
  ms.insert(100); // {-10, 100, 100}
  cout << ms.count(100) << '\n'; // 2
}

void unordered_map_example(){
  unordered_map<string, int> m;
  m["hi"] = 123;
  m["bkd"] = 1000;
  m["gogo"] = 165; // ("hi", 123), ("bkd", 1000), ("gogo", 165)
  cout << m.size() << '\n'; // 3
  m["hi"] = -7;  // ("hi", -7), ("bkd", 1000), ("gogo", 165)
  if(m.find("hi") != m.end()) cout << "hi in m\n";
  else cout << "hi not in m\n";
  m.erase("bkd"); // ("hi", 123), ("gogo", 165)
  for(auto e : m)
    cout << e.first << ' ' << e.second << '\n';
}

int main(void){
  unordered_set_example();  
  unordered_multiset_example();
  unordered_map_example();
}

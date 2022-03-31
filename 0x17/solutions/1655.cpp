// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/d73752df4f1647d6841534ee059a00ed
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, t;
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<>> minHeap;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> t;
    if (maxHeap.size() <= minHeap.size())
      maxHeap.push(t);
    else
      minHeap.push(t);
    if (!minHeap.empty() && minHeap.top() < maxHeap.top()) {
      minHeap.push(maxHeap.top());
      maxHeap.pop();
      maxHeap.push(minHeap.top());
      minHeap.pop();
    }
    cout << maxHeap.top() << '\n';
  }
}
/*
가장 작은 원소부터 pop되는 minHeap,
가장 큰 원소부터 pop되는 maxHeap 두 개를 준비하고
원소들의 큰 쪽 절반은 minHeap에 저장되고
작은 쪽 절반은 maxHeap에 저장되도록 관리합니다.
*/
#include <bits/stdc++.h>
using namespace std;

int n = 10;
int arr[1000001] = {15, 25, 22, 357, 16, 23, -53, 12, 46, 3};

void quick_sort(int st, int en) { // arr[st to en-1]을 정렬할 예정
  if(en <= st+1) return; // 수열의 길이가 1 이하이면 함수 종료.(base condition)
  int pivot = arr[st]; // 제일 앞의 것을 pivot으로 잡는다. 임의의 값을 잡고 arr[st]와 swap해도 상관없음.
  int l = st+1; // 포인터 l
  int r = en-1; // 포인터 r
  while(1){
    while(l <= r && arr[l] <= pivot) l++;
    while(l <= r && arr[r] >= pivot) r--;
    if(l > r) break; // l과 r이 역전되는 그 즉시 탈출
    swap(arr[l], arr[r]);
  }
  swap(arr[st], arr[r]);
  quick_sort(st, r);
  quick_sort(r+1, en);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  quick_sort(0, n);
  for(int i = 0; i < n; i++) cout << arr[i] << ' ';
}

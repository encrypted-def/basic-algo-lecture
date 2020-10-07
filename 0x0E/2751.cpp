// http://boj.kr/31a6d300825e4e2f988c373ad91fccfe
#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
int tmp[1000001]; // merge 함수에서 리스트 2개를 합친 결과를 임시로 저장하고 있을 변수

// mid = (st+en)/2라고 할 때 a[st:mid], arr2[mid:en]은 이미 정렬이 되어있는 상태
void merge(int st, int en){
  int mid = (st+en)/2;
  int lidx = st; // a[st:mid]에서 값을 보기 위해 사용하는 index
  int ridx = mid; // a[mid:en]에서 값을 보기 위해 사용하는 index
  for(int i = st; i < en; i++){
    if(ridx == en) tmp[i] = arr[lidx++];
    else if(lidx == mid) tmp[i] = arr[ridx++];
    else if(arr[lidx] <= arr[ridx]) tmp[i] = arr[lidx++];
    else tmp[i] = arr[ridx++];
  }
  for(int i = st; i < en; i++) arr[i] = tmp[i]; // tmp에 임시저장해둔 값을 a로 다시 옮김
}

// a[st:en]을 정렬하고 싶다.
void merge_sort(int st, int en){
  if(en-st == 1) return; // 길이 1인 경우
  int mid = (st+en)/2;
  merge_sort(st,mid); // st to mid-1을 정렬한다.
  merge_sort(mid,en); // mid to en-1을 정렬한다.
  merge(st,en);
}
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;  
  for(int i = 0; i < n; i++) cin >> arr[i];
  merge_sort(0, n);
  for(int i = 0; i < n; i++) cout << arr[i] << '\n';
}

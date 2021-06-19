// Authored by : twinkite
// Co-authored by : -
// http://boj.kr/6aa20186e0ce4eb18279117cea3d636e
#include <bits/stdc++.h>
using namespace std;

int rule1(int x){
    return 10000+x*1000;
}

int rule2(int x){
    return 1000+x*100;
}

int rule3(int x){
    return x*100;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int res;
    int arr[4];
    for(int i=0;i<3;i++){
        cin>>arr[i];
    }

    if(arr[0]==arr[1] && arr[1]==arr[2] && arr[0]==arr[2]) res = rule1(arr[0]);
    else if(arr[0]!=arr[1] && arr[1]!=arr[2] && arr[0]!=arr[2]){
        sort(arr, arr+3);
        res = rule3(arr[2]);
    } else{
        if(arr[0]==arr[1]) res = rule2(arr[0]);
        else if(arr[1]==arr[2]) res = rule2(arr[1]);
        else res = rule2(arr[0]);
    }
    cout<<res;
    return 0;
}
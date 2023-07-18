// Authored by : kimgon02
// Co-authored by : -
// http://boj.kr/32dfe15c28ef444b96ddc24320ee2dc9
#include <bits/stdc++.h>
using namespace std;
int N, K, ans, arr[1000005];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>K;
    //arr[i]의 의미 : 좌표 i부터 직선이 arr[i]만큼 포함되거나 제외된다.
    //*예시 : 
    //      1. 만약, arr[0] = 2라면, 좌표 0부터 직선 2개가 추가로 포함된다.
    //      2. 만약, arr[8] = -1라면, 좌표 8부터 직선 1개가 제외된다.
    for(int i=0;i<N;i++){
        int l, r;
        cin>>l>>r;
        arr[l]++;
        arr[r]--;
    }
    //ld, rd는, 각각 st, en 값을 1씩 변화 시킬 때, 직선의 합이 몇개씩 변화해야 하는 지에 대한 값을 의미한다.
    //예를 들어, arr[0, 1, 2, 3] = {1, 1, -2, 0 } 고, en가 0부터 3까지 이동하는 상황을
    //가정해보면, rd의 값은 1 -> 2 -> 0 -> 0 과 같이 변한다.
    //sum은, [st, en] 사이의 모든 길이들의 총합을 의미한다.
    int en=0, sum=0;
    int ld=0, rd=0;

    for(int st=0;st<1000001;st++){
        ld+=arr[st];//arr[st] (좌표 st부터 추가되거나 제외되는 직선의 합)을 ld에 더한다.
        while(en+1<1000001&&sum<K){
            rd+=arr[en];//ld와 마찬가지로 rd의 값을 갱신한다.
            sum+=rd;//rd== en을 1증가 시킬 경우, 직선의 합이 몇개 변화 할지에 대한 값
            en++;
        }
        if(sum==K){
            //st, en은 0부터 증가하며, en부터 증가하며 답을 찾기 때문에 처음 찾은 답이 무조건 출력 조건을 만족한다.
            cout<<st<<' '<<en;
            return 0;
        }
        //st가 증가 할 것이므로, ld만큼의 값을 직선들의 합에서 제외한다.
        sum-=ld;

    }
    cout<<"0 0";
    return 0;
}
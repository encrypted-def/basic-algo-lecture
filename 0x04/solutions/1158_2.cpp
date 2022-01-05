// Authored by : seondal
// Co-authored by : -
// http://boj.kr/b17d9819bdf940a1b8284602cbeafdc7

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,k;
    cin >> n >> k;
    
 
    vector <int> V, ans;
    for (int i=1; i<=n; i++)
        V.push_back(i);

    for (int i=0; ans.size() < n; i++){ //정답벡터에 n개의 원소가 쌓이면 종료
        if(i%k == k-1) //t가 k의 배수일때
            ans.push_back(V[i]);
        else
            V.push_back(V[i]);
    }

    cout << "<";
    for(int i=0; i<n; i++){
        if(i == n-1)
            cout << ans[i]; //마지막 요소는 콤마 없이 출력
        else
            cout << ans[i] << ", ";
    }
    cout << ">";

    return 0;
}

/*
 0x03강에서 배운 STL vector을 이용한 풀이
 정답용 벡터를 따로 생성해서 조건에 맞는 원소들을 넣는 방식으로 답을 구함
 */

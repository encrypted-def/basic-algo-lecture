// Authored by : han1222
// http://boj.kr/cfb38e096d28493f9a1bccb8600fbeff
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n;

bool cmp(pair<int,int>  a ,pair<int,int> b){

    if(a.Y!=b.Y)
        return a.Y<b.Y;
    else
        return a.X<b.X;

}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >>n;
    pair<int,int> coord[n];
    for(auto & s : coord) cin>> s.X >>s.Y;  
    sort(coord,coord+n,cmp);
    for(auto p : coord) cout <<p.X<<' '<<p.Y<<'\n';
    return 0;
}



/*
sort의 compare를 이용한 풀이
*/

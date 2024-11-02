vector<int> p(1000001, -1);

int find(int x){
  if(p[x] < 0)
    return x;
  return p[x] = find(p[x]);
}

bool uni(int u, int v){
  u = find(u);
  v = find(v);
  if(u == v)
    return false;
  if(p[v] < p[u]) // v의 랭크가 더 큰 경우
    swap(u, v); // u, v를 swap
  // 위의 if문으로 인해 u의 랭크 >= v의 랭크이다
  if(p[u] == p[v]) // 랭크가 같은 경우에 대한 처리
    p[u]--;
  p[v] = u; // v를 u의 자식으로 만든다  
  return true;  
}

#include <bits/stdc++.h>
typedef long long ll;
//bfs
using namespace std;
//количество компонентов связанности
vector<int> g[100];
queue<int> q;
int used[100];
int dist[100];
int n, m, x , y;

void bfs(int t){
    q.push(t);
    dist[t] = 0;
    used[t] = true;
    while(!q.empty()){
        int v = q.front();
        for(int i = 0;i < g[v].size(); i++){
            int u = g[v][i];
            if(used[u] == false){
                used[u] = true;
                q.push(u);
                dist[u] = dist[v] + 1;


            }
        }
        q.pop();
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);

    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(used[i] == false){
            bfs(i);
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}
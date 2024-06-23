#include <iostream>
#include <vector>
using namespace std;

const int UNVISITED = 0;
const int VISITED = 1;

void dfs(vector<vector<int>>& graph, vector<int>& vis, int node){
    vis[node] = VISITED;
    for(int i = 0; i < graph[node].size(); i++){
        if(vis[graph[node][i]] == UNVISITED)
            dfs(graph, vis, graph[node][i]);
    }
}

int main(){
    int n, m;
    int u, v;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    vector<int> vis(n+1, UNVISITED);

    for(int i = 0; i < m; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(graph, vis, 1);

    int all_visited = 1;
    for(int i = 1; i <= n; i++){
        if(vis[i]==UNVISITED){
            all_visited = 0;
            cout << i << endl;
        }
    }

    if(all_visited)cout << "Connected" << endl;
    return 0;
}
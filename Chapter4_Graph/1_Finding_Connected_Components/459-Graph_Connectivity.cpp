#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int UNVISITED = 0;
const int VISITED = 1;

void dfs(vector<vector<int>>& graph, vector<int>& vis, int node){
    vis[node] = VISITED;
    for(int i = 0; i < graph[node].size(); i++){
        if(vis[graph[node][i]]==UNVISITED){
            dfs(graph, vis, graph[node][i]);
        }
    }
}

int main(){
    int T;
    char highCh;
    int maxNodes;
    string s;
    
    cin>>T;
    while(T--){
        cin >> highCh;
        cin.ignore();
        maxNodes = highCh - 'A' + 1;
        vector<vector<int>> graph(maxNodes);
        vector<int> vis(maxNodes, UNVISITED);

        while(getline(cin, s) && s!=""){
            graph[s[0]-'A'].push_back(s[1]-'A');
            graph[s[1]-'A'].push_back(s[0]-'A');
        }

        int ans = 0;
        for(int i = 0; i < maxNodes; i++){
            if(vis[i]==UNVISITED){
                ans++;
                dfs(graph, vis, i);
            }
        }

        cout << ans << endl;
        if(T)
            cout << endl;
    }
    return 0;
}
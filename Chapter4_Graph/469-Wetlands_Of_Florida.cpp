#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int R;
int C;

int dirx[]={-1,-1,-1,0,0,1,1,1};
int diry[]={1,0,-1,1,-1,1,0,-1};

void dfs(vector<vector<int>>& graph, vector<vector<int>>& vis, int r, int c, int& ans){
    ans++;
    vis[r][c] = 1;
    for(int i = 0; i < 8; i++){
        int x = r + dirx[i];
        int y = c + diry[i];
        if( x >=0 && x < R && y >= 0 && y < C && graph[x][y] == 1 && !vis[x][y]){
            dfs(graph, vis, x, y, ans);
        }
    }
}

int area(vector<vector<int>>& graph, vector<vector<int>>& vis, int r, int c){
    int ans = 0;
    if(graph[r][c]=='L')return ans;

    dfs(graph, vis, r, c, ans);

    return ans;
}

int main(){
    int T, ans;
    string s;

    cin>>T;
    cin.ignore();
    cin.ignore();
 
    while(T--){
        ans = 0;
        vector<vector<int>> graph;

        while(getline(cin, s)){
            if(s.empty()){
                break;
            }
            else if(s[0]=='W' || s[0]=='L'){
                vector<int> rowGraph;
                for(int  i = 0; i < s.length(); i++){
                    if(s[i] == 'L') rowGraph.push_back(0);
                    else rowGraph.push_back(1);
                }
                graph.push_back(rowGraph);
            }
            else{

                R = graph.size();
                C = graph[0].size();

                vector<vector<int>> vis(graph.size(), vector<int>(graph[0].size(), 0));
                int row, column;
                istringstream ss2(s);
                ss2 >> row >> column;
                ans = area(graph, vis, row-1, column-1);
                cout << ans << endl;
                vis.clear();
            }
        
        }
        if(T)
            cout << endl;
    }
    return 0;
}

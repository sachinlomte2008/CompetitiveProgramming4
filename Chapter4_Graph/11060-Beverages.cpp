#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue> 
#include <utility>
#include <sstream>

using namespace std;

std::map<string, int> name_value;
std::map<int, string> value_name;

struct compareval{
    bool operator()(const int& a, const int& b){
        return a > b;
    }
};

int main(){
    int n, m;
    string str, start, end, s;
    int t = 1;
    

    while(getline(cin, s)){
        if(s.empty())continue;
        stringstream ss(s);
        ss >> n;
        vector<vector<int>> graph(n);
        vector<int> ind(n, 0);

        for(int i = 0; i < n; i++){
            cin >> str;
            name_value.insert(make_pair(str, i));
            value_name.insert(make_pair(i, str));
        }
        cin >> m;
        for(int i = 0; i < m; i++){
            cin >> start >> end;
            graph[name_value[start]].push_back(name_value[end]);
            ind[name_value[end]]+=1;
        }

        priority_queue<int, vector<int>, compareval> pq;

        for(int i = 0; i < n; i++){
            if(ind[i]==0)pq.push(i);
        }

        vector<int> order;
        while(!pq.empty()){
            int u = pq.top(); pq.pop();
            order.push_back(u);
            for(int i = 0; i < graph[u].size(); i++){
                ind[graph[u][i]]--;
                if(ind[graph[u][i]] == 0){
                    pq.push(graph[u][i]);
                }
            }
        }

        cout << "Case #" << t << ": Dilbert should drink beverages in this order:";
        for(int i = 0; i < order.size(); i++){
            cout << " " << value_name[order[i]] ;
        }
        cout << "." << endl;
        name_value.clear();
        value_name.clear();
        t++;
        cout << endl;
    }
    return 0;
}
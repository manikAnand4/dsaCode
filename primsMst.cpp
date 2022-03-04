#include<bits/stdc++.h>
using namespace std;

class Graph{
    unordered_map<int, vector<pair<int,int>>> g;
    int v;
public:
    Graph(int vertex){
        this->v=vertex;
    }

    void addEdge(int src, int des, int wt){
        this->g[src].push_back({des, wt});
        this->g[des].push_back({src, wt});
    }

    void getMst(){
        vector<int>visited(v+1, 0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,1}); int ans=0;
        while(!pq.empty()){
            pair<int,int> temp=pq.top();
            pq.pop();
            if(visited[temp.second])
                continue;
            ans=ans+temp.first;
            visited[temp.second]=1;
            for(auto child:g[temp.second]){
                if(visited[child.first]==0){
                    pq.push({child.second, child.first});
                }
            }
        }
        cout<<ans<<endl;
    }
};

int main(){
    Graph g(5);
    g.addEdge(1,2,1);
    g.addEdge(2,3,4);
    g.addEdge(2,4,6);
    g.addEdge(4,5,5);
    g.addEdge(3,5,1);
    g.getMst();
}

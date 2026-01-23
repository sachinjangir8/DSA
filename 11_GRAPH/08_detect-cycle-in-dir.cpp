#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;                       // number of vertices
    vector<vector<int>> adj;     // adjacency list

    bool dfs(int node, vector<bool> &visited, vector<bool> &path) {
        visited[node] = true;//kuki visited hai
        path[node] = true;   //visit karne pr  mark node in current path

        // Explore all neighbors 
        for (int i = 0; i < adj[node].size(); i++) {
            if(path[adj[node][i]]) return true; //if already in path,cycle
            if(visited[adj[node][i]]==false) continue; //if not visited,continue
            if(dfs(adj[node][i],visited,path)) return true; //recursive call
        }
        path[node] = false; // backtrack when i will go back
        return false;
    }

    bool bfs(int node, vector<bool> &visited) {
        vector<int> indegree(V, 0);
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i <V; i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for(auto it: adj[front]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(ans.size()==V) return false; //no cycle
        return true; //cycle

    }
public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);  // directed edge
    }

    bool hasCycle() {
        vector<bool> visited(V, false);
        vector<bool> path(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                // if (dfs(i, visited, path)) //here we passed node,visited,path
                if(bfs(i,visited))
                    return true;
            }
        }
        return false;
       
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);  // cycle here
    g.addEdge(2, 3);

    if (g.hasCycle())
        cout << "Graph contains a cycle\n";
    else
        cout << "Graph does not contain a cycle\n";

    return 0;
}

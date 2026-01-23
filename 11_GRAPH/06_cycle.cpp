#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;                        // number of vertices
    vector<vector<int>> adj;      // adjacency list

    // Recursive DFS helper for cycle detection
    bool dfs(int node, int parent, vector<bool>& visited) {
        visited[node] = true;
        for(int j = 0; j < adj[node].size();j++){
            if(parent==adj[node][j]) continue; // Skip the edge to parent
            if(visited[adj[node][j]]) return true; // Cycle found
            if(dfs(adj[node][j], node, visited)) return true;
         }
         return false;
        // for (int adjlist: adj[node]) {
        //     if(adjlist==parent) continue; // Skip the edge to parent
        //     if(visited[adjlist]) return true; // Cycle found
        //     if(dfs(adjlist, node, visited)) return true;
        // }
        // return false;
    }
     bool bfs(vector<vector<int>>& adj, vector<bool>& visited) {
         queue<pair<int, int>> q;
         visited[0] = true;
         q.push({0, -1}); // Start from node 0 with no parent
         while(!q.empty()) {
             int node = q.front().first;
             int parent = q.front().second;
             q.pop();
             for (int j = 0; j < adj[node].size();j++){
                if(parent==adj[node][j]) continue; // Skip the edge to parent
                if(visited[adj[node][j]]) return true; // Cycle found
                visited[adj[node][j]] = true;  
                q.push({adj[node][j], node});
             }
         }
            return false;
     }
public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    // Add an undirected edge
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Build a simple cycle: 0-1-2-...-(V-1)-0
    void buildCycle() {
        for (int i = 0; i < V; i++) {
            addEdge(i, (i + 1) % V);
        }
    }

    // Print adjacency list
    void printGraph() {
        cout << "Cycle Graph adjacency list:\n";
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (int v : adj[i]) cout << v << " ";
            cout << endl;
        }
    }

    // Detect cycle using DFS
    bool hasCycle() {
        vector<bool> visited(V, false);
        for (int i = 0; i <V;i++){
            if(!visited[i])
            {
                if(dfs(i, -1, visited)) return true;
                // if(bfs(adj,visited)) return true;
            }
        }
        return false;
    }
};

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    Graph g(n);
    g.buildCycle();
    g.printGraph();

    if (g.hasCycle())
        cout << "Cycle detected " << endl;
    else
        cout << "No cycle" << endl;

    return 0;
}
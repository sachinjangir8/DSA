#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;  // number of vertices
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Add edge (undirected graph)
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Function to check if the graph is Bipartite using BFS
    bool isBipartite() {
        vector<int> color(V, -1);  // -1 for uncolored, 0 for red, 1 for blue
        queue<int> q;

        for (int i = 0; i < V;i++){
            if(color[i]==-1){

                q.push(i);
            color[i] = 0;  // Start coloring with red (0)
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for (int i = 0; i < adj[node].size();i++){
                    // If not colored, color with opposite color
                    if(color[adj[node][i]]==-1){
                        color[adj[node][i]]=(color[node]+1)%2;
                        q.push(adj[node][i]);
                    }
                    // If already colored with same color, not bipartite
                    else{
                        if(color[adj[node][i]]==color[node])return false;
                    }
                }
            }
            }
        }
//    you should also try dfs for this

        return true;
    };

    bool isBipartitedfs() {
        vector<int> color(V, -1);  // -1 for uncolored, 0 for red, 1 for blue

        for (int i = i;i<V;i++){
            for (int j = 0; j < adj[j].size();j++)
            {
                // If not colored, color with opposite color
                if(color[adj[i][j]]==-1){
                    color[adj[i][j]]=(color[i]+1)%2;
                }
                // If already colored with same color, not bipartite
                else{
                    if(color[adj[i][j]]==color[i])return false;
                }

            }
        }
        cout<<" this block is working\n";
        return true;
    }
    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (int v : adj[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(6);

    // Create a Bipartite Graph (example)
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(4, 5);

    cout << "Adjacency List:\n";
    g.printGraph();

    if (g.isBipartitedfs())
        cout << " The graph is Bipartite\n";
    else
        cout << " The graph is NOT Bipartite\n";

    return 0;
}

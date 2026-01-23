#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Graph {
    int V; // number of vertices
    vector<vector<int>> adj; // adjacency list

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // add undirected edge
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // print the graph
    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (int v : adj[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    // getter for adjacency list
    const vector<vector<int>>& getAdj() const {
        return adj;
    }

    vector<int> shortestpath(vector<vector<int>>& edges, int n, int m, int src,int dest) {
        vector<int> adjs[n];
        for (int i = 0; i < m;i++){
            adjs[edges[i][0]].push_back(edges[i][1]);
            adjs[edges[i][1]].push_back(edges[i][0]);
        }
        // array distance 
        vector<int> dist(n, -1);
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(src);

        dist[src] = 0;
        visited[src] = true;
        vector<int> parent(n, -1); //parent array to store the path

        while(!q.empty()){
            int node = q.front();
            q.pop();
            // look at all the neighbours of node
            for (int i = 0; i < adjs[node].size();i++){
                if(visited[adjs[node][i]]) continue; //it means already visited hh  to ignore kro 
                visited[adjs[node][i]] = true; //mark visited kr rhe hh agr visit nhi kiya hh 
                q.push(adjs[node][i]);
                dist[adjs[node][i]]=dist[node]+1; //distance update kr rhe hh
                parent[adjs[node][i]]=node; //parent update kr rhe hh
            }
        }
        // return dist;
        vector<int> path;
        while(dest!=-1){
            path.push_back(dest);
            dest=parent[dest];
        }
        reverse(path.begin(),path.end());
        cout<<"Shortest path from source to destination: ";
        return path;
    }
};

int main() {
    Graph g(6);  // graph with 6 vertices (0–5)

    // add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);

    cout << "Undirected Graph (Adjacency List):\n";
    g.printGraph();

     vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 4}, {3, 4}, {3, 5}};
    int n = 6; // number of vertices
    int m = edges.size(); // number of edges
    int src = 5; // starting vertex for shortest path
    int dest = 4;
    vector<int> distances = g.shortestpath(edges, n, m, src, dest);
    cout << "\nShortest distances from source vertex " << src << ":\n";
    for (int i = 0; i < distances.size(); i++) {
        cout << "Vertex " << i << ": " << distances[i] << endl;
    }

    return 0;
}

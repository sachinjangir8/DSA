#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
    int V; // Number of vertices
    // list<int> *adjList; // Array of adjacency lists
    vector<list<int>> adjList;
public:
    Graph(int V) {
        this->V = V;
        // adjList = new list<int>[V]; // Create an array of lists
        adjList.resize(V);
    }

    void addEdge(int u, int v){
        if(u >= V || v >= V || u < 0 || v < 0){
            cout << "Invalid edge: " << u << " - " << v << endl;
            return;
        }
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }

    void printGraph(){
        for (int i = 0; i < V; i++) {
            cout << "Adjacency list of vertex " << i << " ";
            for (auto x : adjList[i]) {
                cout << "-> " << x;
            }
            cout << "\n";
        }
    }
};

int main(){
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    cout << "Enter the number of edges: ";
    cin >> E;

    Graph g(V);

    for (int i = 0; i < E; i++){
        int u, v;
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.printGraph();

    return 0;
}

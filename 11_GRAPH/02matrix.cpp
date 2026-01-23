#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    bool directed;
    bool weighted;
    vector<vector<int>> adjMat;

public:
    Graph(int V, bool directed = false, bool weighted = false) {
        this->V = V;
        this->directed = directed;
        this->weighted = weighted;
        adjMat = vector<vector<int>>(V, vector<int>(V, 0)); // it is a vector of vectors of size V*V initialized to 0
    }

    void addEdge(int u, int v, int w = 1) {
        if (u >= V || v >= V || u < 0 || v < 0) {
            cout << "Invalid edge: " << u << " - " << v << endl;
            return;
        }
        int value = weighted ? w : 1;
        adjMat[u][v] = value;
        if (!directed) {
            adjMat[v][u] = value; // only if undirected
        }
    }

    void printGraph() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << adjMat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    bool directed, weighted;
    cout << "Directed? (1=yes, 0=no): ";
    cin >> directed;
    cout << "Weighted? (1=yes, 0=no): ";
    cin >> weighted;

    Graph g(V, directed, weighted);

    cout << "Enter edges (u v [w]):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w = 1;
        if (weighted) {
            cin >> u >> v >> w;
            g.addEdge(u, v, w);
        } else {
            cin >> u >> v;
            g.addEdge(u, v);
        }
    }

    g.printGraph();
}

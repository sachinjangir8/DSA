#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph {
    int V;                         // number of vertices
    vector<vector<int>> adj;       // adjacency list

    // helper DFS function
    void dfs(int node, vector<bool> &visited, stack<int> &st) {
        visited[node] = true;
        for (int i = 0; i < adj[node].size(); i++) {   // FIXED
            int v = adj[node][i];
            if (!visited[v]) {
                dfs(v, visited, st);
            }
        }
        st.push(node);   // push after visiting children
    }

public:
    Graph(int n) {
        V = n;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);   // directed edge u -> v
    }

    void topoSort() {
        vector<bool> visited(V, false);
        stack<int> stk;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, stk);
            }
        }

        cout << "Topological Sort order: ";
        while (!stk.empty()) {
            cout << stk.top() << " ";
            stk.pop();
        }
        cout << "\n";
    }
    void toposortbfs(){
        vector<int> ans;
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        //jb tki queue khali na ho jaye to ans me push krdo
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        //print ans
        for(auto it: ans) cout<<it<<" ";
        cout<<"\n";
    }

};   // <-- FIXED missing brace

int main() {
    Graph g(6);

    // DAG edges
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topoSort();
    g.toposortbfs();

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class AlienDictionary {
public:
    string findOrder(string dict[], int n, int k) {
        vector<int> adj[k];
        vector<int> indegree(k, 0);

        // Build graph
        for (int i = 0; i < n - 1; i++) {
            string str1 = dict[i], str2 = dict[i + 1];
            int l = 0, m = 0;

            while (l < str1.size() && m < str2.size()) {
                if (str1[l] != str2[m]) {
                    adj[str1[l] - 'a'].push_back(str2[m] - 'a');
                    indegree[str2[m] - 'a']++;
                    break;  // only first mismatch matters
                }
                l++;
                m++;
            }
        }

        // Kahn’s algorithm for Topological Sort
        queue<int> q;
        for (int i = 0; i < k; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        string ans = "";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans += (char)(node + 'a');

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        return ans;
    }
};

int main() {
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
    int n = 5;  // number of words
    int k = 4;  // number of unique characters

    AlienDictionary ad;
    cout << "Alien Dictionary Order: " << ad.findOrder(dict, n, k) << endl;

    return 0;
}

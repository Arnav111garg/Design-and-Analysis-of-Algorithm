#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

// Pair format: {edge_weight, vertex}
using Edge = pair<int, int>;

void primMST(int n, const vector<vector<Edge>>& adj, int start = 0) {
    vector<bool> inMST(n, false);
    vector<int> key(n, 1e9);     // Minimum weight edge connecting vertex to MST
    vector<int> parent(n, -1);   // Stores MST parent of each vertex

    // Min-heap to always pick the edge with smallest weight
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    key[start] = 0;
    pq.push({0, start});

    int mstWeight = 0;
    int edgesIncluded = 0;

    while (!pq.empty() && edgesIncluded < n) {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Skip stale entries if u is already included in the MST
        if (inMST[u]) {
            continue;
        }

        inMST[u] = true;
        mstWeight += weight;
        edgesIncluded++;

        for (const auto& edge : adj[u]) {
            int v = edge.second;
            int w = edge.first;

            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push({w, v});
            }
        }
    }

    if (edgesIncluded < n) {
        cout << "Graph is disconnected; a spanning tree covering all nodes does not exist.\n";
        return;
    }

    cout << "Edges in the Minimum Spanning Tree:\n";
    for (int v = 0; v < n; v++) {
        if (parent[v] != -1) {
            cout << parent[v] << " -- " << v << "  (Weight: " << key[v] << ")\n";
        }
    }
    cout << "Total MST Weight: " << mstWeight << "\n";
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    if (n <= 0) {
        cout << "Number of vertices must be positive.\n";
        return 0;
    }

    vector<vector<Edge>> adj(n);
    cout << "Enter " << m << " edges (u v weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }
    }

    primMST(n, adj, 0);

    return 0;
}
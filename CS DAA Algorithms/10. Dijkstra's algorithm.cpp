#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

using ll = long long;
const ll INF = numeric_limits<ll>::max();

// Pair format: {edge_weight, neighbor_vertex}
using Edge = pair<ll, int>;
// Priority queue element: {current_shortest_distance, vertex}
using State = pair<ll, int>;

void dijkstra(int n, const vector<vector<Edge>>& adj, int source) {
    vector<ll> dist(n, INF);
    vector<int> parent(n, -1);

    priority_queue<State, vector<State>, greater<State>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Skip stale entries if a shorter path to u was already found
        if (d > dist[u]) {
            continue;
        }

        for (const auto& edge : adj[u]) {
            int v = edge.second;
            ll w = edge.first;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\nShortest paths from source node " << source << ":\n";
    for (int v = 0; v < n; v++) {
        cout << "To node " << v << ": ";
        if (dist[v] == INF) {
            cout << "Unreachable\n";
            continue;
        }

        cout << "Distance = " << dist[v] << ", Path = ";
        vector<int> path;
        for (int curr = v; curr != -1; curr = parent[curr]) {
            path.push_back(curr);
        }
        for (int i = static_cast<int>(path.size()) - 1; i >= 0; i--) {
            cout << path[i] << (i > 0 ? " -> " : "");
        }
        cout << "\n";
    }
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
    bool directed;
    cout << "Is the graph directed? (1 for Yes, 0 for No): ";
    cin >> directed;

    cout << "Enter " << m << " edges (u v weight) with non-negative weights:\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        if (w < 0) {
            cout << "Warning: Negative weight detected. Dijkstra assumes non-negative edge weights.\n";
        }
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj[u].push_back({w, v});
            if (!directed) {
                adj[v].push_back({w, u});
            }
        }
    }

    int source;
    cout << "Enter source node (0 to " << n - 1 << "): ";
    cin >> source;

    if (source < 0 || source >= n) {
        cout << "Invalid source node.\n";
        return 0;
    }

    dijkstra(n, adj, source);

    return 0;
}
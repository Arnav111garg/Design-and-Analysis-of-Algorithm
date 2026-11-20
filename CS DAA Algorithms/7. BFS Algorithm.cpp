#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Node {
    int id;
    string data;
};

void bfs(int startNode, const vector<Node>& nodes, const vector<vector<int>>& adj) {
    int n = nodes.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    cout << "BFS Traversal starting from node " << startNode << ":\n";

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        cout << "Node " << nodes[curr].id << " -> " << nodes[curr].data << "\n";

        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    if (n <= 0) {
        cout << "Number of nodes must be positive.\n";
        return 0;
    }

    vector<Node> nodes(n);
    cout << "Enter data (single word) for each node (0 to " << n - 1 << "):\n";
    for (int i = 0; i < n; i++) {
        nodes[i].id = i;
        cin >> nodes[i].data;
    }

    vector<vector<int>> adj(n);
    bool directed;
    cout << "Is the graph directed? (1 for Yes, 0 for No): ";
    cin >> directed;

    cout << "Enter " << m << " edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj[u].push_back(v);
            if (!directed) {
                adj[v].push_back(u);
            }
        }
    }

    int startNode;
    cout << "Enter starting node (0 to " << n - 1 << "): ";
    cin >> startNode;

    if (startNode < 0 || startNode >= n) {
        cout << "Invalid starting node.\n";
        return 0;
    }

    bfs(startNode, nodes, adj);

    return 0;
}